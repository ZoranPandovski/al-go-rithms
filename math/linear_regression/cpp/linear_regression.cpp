#include "linear_regression.hpp"

std::pair<double, double> linear_regression(const std::vector<double> &x, const std::vector<double> &y, unsigned int n)
{
    double sumOfMul = 0;
    double sumOfX = 0;
    double sumOfY = 0;
    double sumOfSquareX = 0;

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

    const double a = (n*sumOfMul - sumOfX*sumOfY) / denominator;
    const double b = (sumOfSquareX*sumOfY - sumOfX*sumOfMul) / denominator;

    return std::make_pair(a, b);
}