#include <iostream> 

using namespace std;

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
	cout << "Please enter two numbers." << endl;
	cin >> num1 >> num2;

	long long lcm = __lcm(num1, num2);
	cout << "LCM of " << num1 << " and " << num2 << " is " << lcm << endl;
	return 0;
}
