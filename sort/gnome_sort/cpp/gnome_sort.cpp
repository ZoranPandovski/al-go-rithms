#include "gnome_sort.hpp"

template <typename T>
void gnome_sort(std::vector<T> &input, unsigned int n)
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

template <typename T>
void swap(T &lhs, T &rhs)
{
    T temp = lhs;
    lhs = rhs;
    rhs = temp;
}