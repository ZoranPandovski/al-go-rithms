#include <iostream>
#include <vector>
#include <utility>
#include "linear_regression.hpp"



int main()
{
    std::vector<double> x = {0, 1, 2, 3, 4, 5};
    std::vector<double> y = {0, 2, 4, 6, 8, 10};

    std::pair<double, double> res = linear_regression(x, y, 6);

    std::cout << res.first << ' ' << res.second << '\n';

    return 0;
}