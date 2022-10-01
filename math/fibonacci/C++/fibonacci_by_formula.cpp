#include <iostream>
#include <math.h>

/*
 * The code below calculates N-th fibonacci number by O(1)
 * Such speed is achieved by using the Binet's formula which is
 * fib(n) = (phi^n - psi^n) / sqrt(5)
 * where
 * phi = (1 + sqrt(5)) / 2 and psi = (1 - sqrt(5)) / 2
 * But in code we compute fib(n) as
 * fib(n) = round(phi^n) / sqrt(5)
 * because when n -> inf: abs(psi^n) -> 0
 * When n is small this formula is innacurate because
 * we are computing in double and float and they aren't the exact values that we have in Math
 * Because of the same reasons we may have slightly innacurate values with small n.
 */

long fib(long n) {
	double phi = (1 + sqrt(5)) / 2;
	return round(pow(phi, n)) / sqrt(5);
}

int main() {
	long n = 50;
  std::cout << fib(n);
}