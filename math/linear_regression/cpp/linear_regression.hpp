#ifndef LINEAR_REGRESSION
#define LINEAR_REGRESSION

#include <utility>
#include <vector>

template <typename T>
std::pair<T, T> linear_regression(const std::vector<T> &x, const std::vector<T> &y, unsigned int n)
{
    T sumOfMul = 0;
    T sumOfX = 0;
    T sumOfY = 0;
    T sumOfSquareX = 0;

    unsigned int i = 0;
    for (; i < n; ++i)
    {
        sumOfMul += x[i] * y[i];
    }
    
    for (i = 0; i < n; ++i)
    {
        sumOfX += x[i];
    }

    for (i = 0; i < n; ++i)
    {
        sumOfY += y[i];
    }

    for (i = 0; i < n; ++i)
    {
        sumOfSquareX += x[i] * x[i];
    }
    const double denominator = (n*sumOfSquareX - sumOfX*sumOfX);

    const double m = (n*sumOfMul - sumOfX*sumOfY) / denominator;
    const double b = (sumOfSquareX*sumOfY - sumOfX*sumOfMul) / denominator;

    return std::make_pair(m, b);
}

#endif