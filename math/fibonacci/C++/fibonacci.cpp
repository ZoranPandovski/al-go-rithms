// MOD AUTHOR:  Taylor Hudson
// GITHUB    :  https://github.com/allencompsci
// DATE      :  October 20, 2017
// DESCRITION:  This C++ program implements the factorial operation in a space efficient, non-recursive manner and works beyond long long


#include <iostream>
#include <string>

std::string add(std::string a, std::string b) { // ADDED 
	std::string temp = "";
	while ((int)a.length() < (int)b.length()) {
		a = "0" + a;
	}
	while ((int)b.length() < (int)a.length()) {
		b = "0" + b;
	}
	int carry = 0;
	for (int i = a.length() - 1; i >= 0; i--) {
		char val = (char)(((a[i] - 48) + (b[i] - 48)) + 48 + carry);
		if (val > 57) {
			carry = 1;
			val -= 10;
		}
		else {
			carry = 0;
		}
		temp = val + temp;
	}
	if (carry != 0) {
		temp = "1" + temp;
	}
	while (temp[0] == '0' && temp.length() != 1) {
		temp = temp.substr(1);
	}
	return temp;
}

void fib_Accurate(long long n) { // ADDED
	std::string tmp = "";
	std::string fibMinus1 = "1";
	std::string fibMinus2 = "0";
	std::string comma = ", ";
		for (long long i = 0; i < n; i++) {
			tmp = add(fibMinus1, fibMinus2);
			std::cout << comma <<  fibMinus2;
			fibMinus2 = fibMinus1;
			fibMinus1 = tmp;
	}
}

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
	long long n; // MODIFIED
	int a = 0, b = 1;
	std::cout << "How many numbers would you like to compute?\n>> ";
	std::cin >> n;

	fib((int)n, a, b); // MODIFIED
	fib_Accurate(n); // ADDED
	return 0;
}
