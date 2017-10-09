// AUTHOR:      Mitchell Haugen
// GITHUB:      https://github.com/haugenmitch
// DATE:        October 9, 2017
// DESCRIPTION: This C++ program implements the factorial operation in a space efficient, non-recursive manner

// TEST VALUES:
// 0!  = 1
// 1!  = 1
// 2!  = 2
// 3!  = 6
// 5!  = 120
// 10! = 3,628,800
// 20! = 2,432,902,008,176,640,000

#include <iostream>

long long int factorial(int n){
	if (n < 2){
		return 1;
	}
	
	long long int output = 1;
	for (int i = n; i > 1; i--){
		output *= i;
	}

	return output;
}

int main() {
	int userInput;
	std::cout << "Enter a positive integer: " << std::endl;
	std::cin >> userInput;
	std::cout << "The factorial is: " << factorial(userInput) << std::endl;

	return 0;
}