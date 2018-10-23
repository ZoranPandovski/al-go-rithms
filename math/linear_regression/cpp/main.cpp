#include <iostream>
#include <vector>
#include <utility>
#include "linear_regression.hpp"


/*
    Linear regression

        n * sum(Xi, Yi) - sum(Xi)*sum(Yi)
    m = ---------------------------------
        n * sum(Xi * Xi) - [sum(Xi)]^2

        sum(Xi * Xi) * sum(Yi) - sum(Xi) * sum(Xi, Yi)
    b = ---------------------------------;
        n * sum(Xi * Xi) - [sum(Xi)]^2

    It takes 3 arguments: set of (x, y) points and an 'n' as a size of vectors
    Returns: std::pair(double, double)
*/

int main()
{
    std::vector<double> x = {0, 1, 2, 3, 4, 5};
    std::vector<double> y = {-1, 1, 3, 5, 7, 9};

    std::pair<double, double> res = linear_regression<double>(x, y, 6);

    std::cout << res.first << ' ' << res.second << '\n';

    return 0;
}