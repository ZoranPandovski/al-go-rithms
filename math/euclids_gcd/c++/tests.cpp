#include <iostream>

#include "euclids_gcd.hpp"

using std::cout;
using std::endl;

int main()
{
	cout << euclids_gcd(1, 10) << endl;

	cout << euclids_gcd(2, 4) << endl;

	cout << euclids_gcd(2, 9) << endl;

	cout << euclids_gcd(37, 91) << endl;
}