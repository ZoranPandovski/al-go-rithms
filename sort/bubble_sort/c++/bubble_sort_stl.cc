#include <iostream>

template <typename T>
inline void swap(T& a, T& b) {
    T tmp = a;
    a = b;
    b = tmp;
}

template <typename, int>
class BubbleSort;
template <typename, bool, int, int>
class BubbleSortInnerLoop;
template <typename, bool, int, int, int>
class BubbleSortOuterLoop;
template <typename, int, int>
class BubbleSortCompareAndSwap;

template <typename T, int N>
class BubbleSort {
public:
    static inline void sort(T* data) {
        BubbleSortInnerLoop<T, true, 0, N>::loop(data);
    }
};

template <typename T, bool doContinue, int I, int N>
class BubbleSortInnerLoop {
private:
    static const bool keepGoing = (I < (N - 1));
public:
    static inline void loop(T* data) {
        BubbleSortOuterLoop<T, true, I, I + 1, N>::loop(data);
        BubbleSortInnerLoop<T, keepGoing, I + 1, N>::loop(data);
    }
};

template <typename T, int I, int N>
class BubbleSortInnerLoop <T, false, I, N> {
public:
    static inline void loop(T* data) {}
};

template <typename T, bool doContinue, int I, int J, int N>
class BubbleSortOuterLoop {
private:
    static const bool keepGoing = (J < N);
public:
    static inline void loop(T* data) {
        BubbleSortCompareAndSwap<T, I, J>::compareAndSwap(data);
        BubbleSortOuterLoop<T, keepGoing, I, J + 1, N>::loop(data);
    }
};

template <typename T, int I, int J, int N>
class BubbleSortOuterLoop<T, false, I, J, N> {
public:
    static inline void loop(T* data) {}
};

template <typename T, int I, int J>
class BubbleSortCompareAndSwap {
public:
    static inline void compareAndSwap(T* data) {
        if (data[I] > data[J]) {
            swap<T>(data[I], data[J]);
        }
    }
};

int main() {
    float a[] = {5.5, 4.4, 3.3, 2.2, 1.1};
    BubbleSort<float, 5>::sort(a);
    for (int i = 0 ; i < 5; ++i) {
        std::cout << a[i] << std::endl;
    }
}