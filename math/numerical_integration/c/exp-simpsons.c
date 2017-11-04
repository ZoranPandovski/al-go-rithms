
#include <stdio.h>
#include <math.h>

void main()
{
int n;
float a = 0, b = 4;
float simps(float a, float b, int n);
printf("Enter the value of n\n");
scanf("%d", &n);
printf("Integral value of f(x) by Simpson's rule:%f\n", simps(a, b, n));
}

float f(float x)
{
	return exp(x);
}

float simps(float a, float b, int n)
{
	float x, y[21], h, sum;
	int i;
	h = (b - a) / n;
	x = a;
	for(i = 0; i <= n; i++){
		y[i] = f(x);
		x = x + h;
	}
	sum = y[0] + y[n];
	for(i = 1; i <= n - 1; i += 2)
		sum += 4 * y[i] + 2 * y[i + 1];
		sum -= 2 * y[n];
		sum = sum * h / 3.0;
		return sum;
}


