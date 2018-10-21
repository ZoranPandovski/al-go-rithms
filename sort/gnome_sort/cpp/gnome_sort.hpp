#ifndef BUBBLE_SORT
#define BUBBLE_SORT

/**
* Gnome sort (Stupid sort)
* Algorithm Steps:
* 1. Starts from 2nd element of a vector
* 2. If current element is larger than previous one, go one step further
* 3. If current element is smaller than the previous one then swap these two elements and go one step backwards
* 4. Return to step 2, until you reach element n - 1
* 5. When you reach end, vector is sorted
*/

#include <vector>

/**
* swap() - Swaps to element in memory
*/
template <typename T>
void swap(T &lhs, T &rhs)
{
    T temp = lhs;
    lhs = rhs;
    rhs = temp;
}

/**
* gnome_sort() - Sorts a vector using gnome sort algorithm.
* Require two arguments: vector and its size
*/
template <typename T>
void gnome_sort(std::vector<T> &input, size_t n)
{
    unsigned int i = 1;
    while (i < n)
    {
        if (input[i] >= input[i - 1])
        {
            i++;
        }

        if (input[i] < input[i - 1])
        {
            swap(input[i], input[i - 1]);
            i--;
        }
    }
}

#endif