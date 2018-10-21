#include <iostream>
#include <vector>
#include "gnome_sort.hpp"

int main()
{
    std::vector<double> arr = {0.0, 0.2, 0.01, 0.6, 0.0, 0.15, 0.01, 10, 0.54, 0.2};
    unsigned int n = arr.size();

    gnome_sort(arr, n);

    for (double val : arr)
    {
        std::cout << val << ' ';
    }
    std::cout << '\n';
    return 0;
}