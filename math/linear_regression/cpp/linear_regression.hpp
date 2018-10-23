#ifndef LINEAR_REGRESSION
#define LINEAR_REGRESSION

#include <utility>
#include <vector>

std::pair<double, double> linear_regression(const std::vector<double> &x, const std::vector<double> &y, unsigned int n);

#endif