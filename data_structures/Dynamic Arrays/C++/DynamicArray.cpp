#include <cassert>
#include <cstddef>
#include <memory>
#include <stdexcept>
#include <type_traits>

/// Dynamic array.
///
/// Grows exponentially.
/// Copies deeply.
template <typename T>
class dynamic_array {
public:
    using iterator = T*;
    using const_iterator = const T*;
    using reference = T&;
    using size_type = std::size_t;

    /// Constructs an empty array.
    dynamic_array() :
        data(nullptr),
        data_end(nullptr),
        data_capacity(nullptr)
    {}

    /// Copies the other array deeply.
    dynamic_array(const dynamic_array& other) : 
        data(new storage_type[other.size()]),
        data_end(reinterpret_cast<storage_type*>(std::uninitialized_copy(other.begin(), other.end(), begin()))),
        data_capacity(data_end)
    {}

    /// Move other into this.
    dynamic_array(dynamic_array&& other) :
        data(std::exchange(other.data, nullptr)),
        data_end(std::exchange(other.data_end, nullptr)),
        data_capacity(std::exchange(other.data_capacity, nullptr))
    {}

    /// Copies the other array deeply. Destroys elements in this.
    dynamic_array& operator=(const dynamic_array& other) {
        clear();
        ensure_capacity(other.size());
        data_end = reinterpret_cast<storage_type*>(std::uninitialized_copy(other.begin(), other.end(), begin()));
        return *this;
    }

    /// Swaps arrays.
    dynamic_array& operator=(dynamic_array&& other) {
        std::swap(data, other.data);
        std::swap(data_end, other.data_end);
        std::swap(data_capacity, other.data_capacity);
        return *this;
    }

    /// Destroys all elements and frees memory.
    ~dynamic_array() {
        std::destroy(begin(), end());
        delete[] data;
    }

    /// Get the begin iterator.
    auto begin() -> iterator {
        return reinterpret_cast<iterator>(data);
    }

    /// Get the end iterator.
    auto end() -> iterator {
        return reinterpret_cast<iterator>(data_end);
    }

    /// Get the begin iterator.
    auto begin() const -> const_iterator {
        return reinterpret_cast<const_iterator>(data);
    }

    /// Get the end iterator.
    auto end() const -> const_iterator {
        return reinterpret_cast<const_iterator>(data_end);
    }

    /// Get the size of the array.
    auto size() const -> size_type {
        return data_end - data;
    }

    /// Get the capacity of the allocated memory.
    auto capacity() const -> size_type {
        return data_capacity - data;
    }

    /// Clears the array.
    /// Capacity is not affected.
    void clear() {
        std::destroy(begin(), end());
        data_end = data;
    }

    /// Gets the element at the index.
    /// Does not perform bounds checking.
    auto operator[](const size_type index) -> reference {
        assert(index < size());
        return begin()[index];
    }

    /// Gets the element at the index.
    /// @exception std::out_of_range Index is out of range.
    auto at(const size_type index) -> reference {
        if (index >= size()) {
            throw std::out_of_range("dynamic_array: index out of bounds");
        }
        return begin()[index];
    }

    /// Directly constructs an element onto the back of the array.
    /// Will allocate more memory and move the array if necessary.
    template <typename... Args>
    void emplace_back(Args&&... args) {
        ensure_capacity(size() + 1);
        new (data_end) T(std::forward<Args>(args)...);
        ++data_end;
    }

    /// Copies an object onto the back of the array.
    void push_back(const T& val) {
        emplace_back(val);
    }

    /// Moves an object onto the back of the array.
    void push_back(T&& val) {
        emplace_back(std::move(val));
    }

    /// Gets the last element.
    auto back() -> reference {
        assert(size() > 0);
        return (*this)[size() - 1];
    }

    /// Removes the last element.
    void pop_back() {
        assert(size() > 0);
        std::destroy_at(end() - 1);
        --data_end;
    }

private:
    using storage_type = std::aligned_storage_t<sizeof(T), alignof(T)>;

    void ensure_capacity(const size_type need_size) {
        if (need_size > capacity()) {
            const auto new_data_capacity = std::max(need_size, capacity() * 2);
            const auto new_data = new storage_type[new_data_capacity];
            const auto new_data_end = std::uninitialized_move(begin(), end(), reinterpret_cast<iterator>(new_data));
            std::destroy(begin(), end());
            delete[] data;
            data = new_data;
            data_end = reinterpret_cast<storage_type*>(new_data_end);
            data_capacity = new_data + new_data_capacity;
        }
    }

    storage_type* data;
    storage_type* data_end;
    storage_type* data_capacity;
};

// TEST

#include <iostream>

int main() {
    auto arr = dynamic_array<int>();

    auto print_stats = [&arr]{
        std::cout << "Size: \t" << arr.size() << ", Capacity: \t" << arr.capacity() << "\n";
    };

    for (auto i = 0; i < 10; ++i) {
        print_stats();
        arr.push_back(i);
        std::cout << "push_back(" << i << ")\n";
    }

    print_stats();

    for (auto& val : arr) {
        std::cout << "Val: " << val << "\n";
    }

    std::cout << "arr[5]: " << arr[5] << "\n";

    std::cout << "arr.back(): " << arr.back() << "\n";

    arr.pop_back();
    arr.pop_back();
    arr.pop_back();

    print_stats();

    // Copy construct.
    auto arr2 = arr;

    // Clear.
    arr.clear();

    print_stats();

    // Move assign.
    arr = std::move(arr2);

    print_stats();

    // Move construct.
    auto arr3 = std::move(arr);

    print_stats();

    // Copy assign.
    arr = arr3;

    print_stats();

    for (auto& val : arr) {
        std::cout << "Val: " << val << "\n";
    }

    // Intentionally cause an out_of_range error.
    arr.at(999);
}
