#include <chrono>
#include <iostream>
#include <thread>
#include <vector>
#include <cassert>
#include <string>

std::vector<int> sleep_sort(std::vector<int> &vec)
{
    std::vector<std::thread> threads;
    std::vector<int> sorted;
    for (int i = 0; i < vec.size(); i++)
    {
        threads.emplace_back([i, vec, &sorted]()
                             {
                                 int arg = vec[i];
                                 std::this_thread::sleep_for(std::chrono::seconds(arg));
                                 sorted.push_back(arg);
                             });
    }

    for (auto &thread : threads)
    {
        thread.join();
    }
    return sorted;
}

void test()
{
    std::vector<int> vec = {5, 4, 3, 2, 1};
    std::vector<int> test_vector;
    std::vector<int> valid = {1, 2, 3, 4, 5};
    test_vector = sleep_sort(vec);
    assert(test_vector == valid);
}

int main()
{
    std::vector<int> input;
    int number;
    int no_of_elems;
    std::cout << "Enter the number of elements" << std::endl;
    std::cin >> no_of_elems;
    std::cout << "Enter the elements" << std::endl;
    for (int i = 0; i < no_of_elems; i++)
    {
        std::cin >> number;
        input.push_back(number);
    }
    test();
    std::vector<int> sorted = sleep_sort(input);
    std::cout << "Sorted: ";
    for (int x : sorted)
    {
        std::cout << x << " ";
    }
}