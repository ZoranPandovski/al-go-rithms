// INCLUDES
#include <iostream>
#include <math.h>

using namespace std;

// DECLARE VARIABLES
int pos = 0;
string result = "";
int number;

// MAIN FUNCTION
int main ()
{
    cin >> number;

    while (1) {
	// Tests if number is divisible by 2^n amd that the next number (2^(n+1)) is also divisible, if 2^n is taken away.
        if (pow(2, pos) <= number && ((int)(number - pow(2, pos)) % (int)(pow(2, pos+1)) == 0)) {
            result = "1" + result;
            number = number - pow(2, pos);
        }
        else { result = "0" + result; }
        if (pow(2, pos) > number) { break; }  // Breaks the loop when 2^n > number entered originally
        pos++;
    }
    cout << result << endl;  // Print the result
    return 0;
}
