// INCLUDES

#include <iostream>
#include <math.h>


// DECLARE VARIABLES

int pos = 0;
std::string result = "";


// MAIN FUNCTION

int main ()
{
	  int number;
    std::cin >> number;

    while (1) {
        if (pow(2, pos) <= number && ((int)(number - pow(2, pos)) % (int)(pow(2, pos+1)) == 0)) {  // Tests if number is divisible by 2^n and that if it is, the next number (2^(n+1)) is also divisible.
            result = "1" + result;
            number = number - pow(2, pos);
        }
        else { result = "0" + result; }

        if (pow(2, pos) > number) { break; }
        pos++;
    }

    std::cout << result << std::endl;  // Print the result

	return 0;
}
