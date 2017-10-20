// AUTHOR:      Mitchell Haugen
// GITHUB:      https://github.com/haugenmitch
// DATE:        October 9, 2017
// DESCRIPTION: This C++ program implements the factorial operation in a space efficient, non-recursive manner

// MOD AUTHOR:  Taylor Hudson
// GITHUB    :  https://github.com/allencompsci
// DATE      :  October 19, 2017
// DESCRITION:  This C++ program implements the factorial operation in a space efficient, non-recursive manner and works beyond long long


// TEST VALUES:
// 0!  = 1
// 1!  = 1
// 2!  = 2
// 3!  = 6
// 5!  = 120
// 10! = 3,628,800
// 20! = 2,432,902,008,176,640,000
// PREVIOUS 55! ERROR
// 55! = 2696403353658275925965100847566516959580321051449436762275840000000000000 

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
std::string sub(std::string a, std::string b) { // ADDED 
	std::string temp = "";
	while ((int)a.length() < (int)b.length()) {
		a = "0" + a;
	}
	while ((int)b.length() < (int)a.length()) {
		b = "0" + b;
	}
	int carry = 0;
	for (int i = a.length() - 1; i >= 0; i--) {
		char val = (char)(((a[i] - 48) - (b[i] - 48)) + 48 + carry);
		if (val < 48) {
			carry = -1;
			val += 10;
		}
		else {
			carry = 0;
		}
		temp = val + temp;
	}
	while (temp[0] == '0' && temp.length() != 1) {
		temp = temp.substr(1);
	}
	return temp;
}
std::string multi(std::string a, std::string b) { //ADDED
	std::string temp = a;
	if ((int)a.length() < (int)b.length()) {
		a = b;
		b = temp;

	}
	temp = a;
	while (b != "1") {
		temp = add(temp, a);
		b = sub(b, "1");
	}
	return temp;
}
std::string factorial_big(int n) { // ADDED
	std::string term = std::to_string(n);
	std::string fact = "1";
	while (term != "0") {
		fact = multi(fact, term);
		term = sub(term, "1");
	}
	return fact;
}

long long int factorial(int n) {
	if (n < 2) {
		return 1;
	}

	long long int output = 1;
	for (int i = n; i > 1; i--) {
		output *= i;
	}

	return output;
}

int main() {
	int userInput;
	std::cout << "Enter a positive integer: " << std::endl;
	std::cin >> userInput;
	std::cout << "The factorial is: " << factorial(userInput) << std::endl;
	std::cout << "The factorial is: " << factorial_big(userInput) << std::endl;
	return 0;
}
