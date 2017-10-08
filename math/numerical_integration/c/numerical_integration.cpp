template<class T>
T IntegrateNumerically(T(*f)(double), double leftEndpoint, double rightEndpoint, double stepSize)
{
	T integral = T();
	double halfStepSize = stepSize / 2;

	double x = leftEndpoint;
	while (x < rightEndpoint)
	{
		x += halfStepSize;
		integral += f(x) * stepSize;
		x += halfStepSize;
	}

	return integral;
}
