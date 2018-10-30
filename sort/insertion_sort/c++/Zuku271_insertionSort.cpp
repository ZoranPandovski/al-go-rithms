#include <iostream>
#include <vector>

/**
* insertionSort()
* @arg: std::vector<T> & - reference to input array of type T
* @return: void
*/
template <typename T>
void insertionSort(std::vector<T> &input)
{
    const unsigned int vector_size = input.size();
    for (unsigned int i = 1; i < vector_size; i++)
    {
        const T tmp = input[i];
        int j = i - 1;

        for (; j >= 0 && input[j] > tmp; j--)
        {
            input[j+1] = input[j];
        }
        input[j + 1] = tmp;
    }
}

int main()
{
    std::vector<int> arr = {17, 19, 1, 5, 6, 5, 4, 9, 10, 0, 2, 6, 8, 9};

    insertionSort(arr);
    for (int t : arr)
    {
        std::cout << t << ' ';
    }
    std::cout << '\n';

    return 0;
}