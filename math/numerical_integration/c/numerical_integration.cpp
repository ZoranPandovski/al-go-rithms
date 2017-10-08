#include<iostream>

template<class T> //Normally T = double, but could for example be used to integrate functions f : R -> C if necessary operators are defined.
T IntegrateNumerically(T(*f)(double), double leftEndpoint, double rightEndpoint, double stepSize)
{
	T integral = T();
	double halfStepSize = stepSize / 2;

	double x = leftEndpoint;
	while (x < rightEndpoint)
	{
		x += halfStepSize;
		integral += f(x) * stepSize; //For an integrable function it doesn't matter exactly where we evaluate f, but halfway through seems fairest.
		x += halfStepSize;
	}

	return integral;
}

//Tests
int main()
{
	std::cout << IntegrateNumerically<double>(&sin, 0, 1, 0.001) << std::endl; //Should be 1 - cos(1)
	std::cout << IntegrateNumerically<double>(&log, 1, 2, 0.001) << std::endl; //Should be 2log(2) - 1
	std::cout << IntegrateNumerically<double>(&exp, -1, 1, 0.001) << std::endl; //Should be e - 1/e
	std::cin.get();
}
