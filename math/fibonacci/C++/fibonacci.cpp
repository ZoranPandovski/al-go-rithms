#include <iostream>

void fib(int n, int a, int b) {
	int tmp;
	for(int i = 0; i < n; i++) {
		std::cout << a << " ";
		tmp = a + b;
		a = b;
		b = tmp;
	}
}

int main() {
	int n;
	int a = 0, b = 1;
	std::cout << "How many numbers would you like to compute?\n>> ";
	std::cin >> n;

	fib(n, a, b);
	return 0;
}