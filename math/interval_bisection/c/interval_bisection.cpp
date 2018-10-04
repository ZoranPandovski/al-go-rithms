#include<iostream>
#include<math.h>
#include<exception>

double IntervalBisection(double(*f)(double), double a, double b, double error)
{
	double fa = f(a), fb = f(b);
	if (fa * fb > 0) throw std::invalid_argument("Interval Bisection requires [a,b] with f(a)f(b) < 0");

	if (abs(fa) < error) return a;
	if (abs(fb) < error) return b;
	double c = (a + b) * 0.5;
	double fc = f(c);
	if (fa * fc < 0) return IntervalBisection(f, a, c, error);
	else return IntervalBisection(f, c, b, error);
}

//For testing the above function
double squareminustwo(double d)
{
	return (d * d) - 2;
}

double expminustwo(double d)
{
	return exp(d) - 2;
}

int main()
{
	std::cout << IntervalBisection(&cos, 1, 2, 0.01) << std::endl; //Should be pi/2
	std::cout << IntervalBisection(&squareminustwo, 1, 2, 0.01) << std::endl; //Should be sqrt(2)
	std::cout << IntervalBisection(&expminustwo, 0, 1, 0.01) << std::endl; //Should be log(2)
	std::cin.get();
}
