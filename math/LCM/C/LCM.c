#include <stdio.h> 

long long __gcd(long long a, long long b) {
	if(b == 0) 
		return a;
	return __gcd(b, a % b);
}

long long __lcm(long long a, long long b) {
	return a * b / __gcd(a, b);
}

int main() {
	long long num1, num2;
	printf("Please enter two numbers.\n");
	scanf("%lld %lld", &num1, &num2);

	long long lcm = __lcm(num1, num2);
	printf("LCM of %lld and %lld is %lld\n", num1, num2, lcm);
	return 0;
}
