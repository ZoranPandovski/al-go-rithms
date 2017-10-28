#include<bits/stdc++.h>
using namespace std;
// some global variables to help save space - we'll be using these a lot.
// coeff = coefficient
double coeff1;
double coeff2;
double coeff3;
double exponent1;
double exponent2;
double exponent3;
// Function prototype
void fun_derivative();

int main()
{
     fun_derivative();
 return 0;
}
//DERIVATIVES
void fun_derivative()
{
 string num_coeff;
 while (num_coeff != "4") // keep user in this menu until they leave.
{
 // I love these menus.
 cout << "\n\n**********************"
    << "\n\n*DERIVATIVES*"
    << "\n\nMonomial or polynomial?"
    << "\n 1. 1 coefficient"
    << "\n 2. 2 coefficients"
    << "\n 3. 3 coefficients"
    << "\n 4. Return to previous screen"
    << "\n\nEnter choice: ";
 cin >> num_coeff;

 if (num_coeff == "1")
    {
     cout << "\n\nEnter value of coefficient: ";
     cin >> coeff1;
     cout << "\nEnter value of exponent: ";
     cin >> exponent1;
     // here we're just showing what they entered and what the new
     // derivative is.
     // formula: f(x) = x^r --> f'(x) = rx^(r-1)
     cout << "\n\nYou entered: "
    << coeff1 << "x^" << exponent1
    << "\n\nYour new derivative is: "
    << exponent1 * coeff1 << "x^" << exponent1 - 1 << endl;
    }
 else if (num_coeff == "2")
    {
     cout << "\n\nEnter value of coefficient 1: ";
     cin >> coeff1;
     cout << "\nEnter value of exponent 1: ";
     cin >> exponent1;
     cout << "\n\nEnter value of coefficient 2: ";
     cin >> coeff2;
     cout << "\nEnter value of exponent 2: ";
     cin >> exponent2;
     // same as above, just twice as long!
     cout << "\n\nYou entered: "
    << coeff1 << "x^" << exponent1 << " + "
    << coeff2 << "x^" << exponent2
    << "\n\nYour new derivative is: "
    << exponent1 * coeff1 << "x^" << exponent1 - 1 << " + "
    << exponent2 * coeff2 << "x^" << exponent2 - 1 << endl;
    }
 else if (num_coeff == "3")
    {
     cout << "\n\nEnter value of coefficient 1: ";
     cin >> coeff1;
     cout << "\nEnter value of exponent 1: ";
     cin >> exponent1;
     cout << "\n\nEnter value of coefficient 2: ";
     cin >> coeff2;
     cout << "\nEnter value of exponent 2: ";
     cin >> exponent2;
     cout << "\n\nEnter value of coefficient 3: ";
     cin >> coeff3;
     cout << "\nEnter value of exponent 3: ";
     cin >> exponent3;
     // same again, 3x the length. See why global variables are good?
     cout << "\n\nYou entered: "
    << coeff1 << "x^" << exponent1 << " + "
    << coeff2 << "x^" << exponent2 << " + "
    << coeff3 << "x^" << exponent3
    << "\n\nYour new derivative is: "
    << exponent1 * coeff1 << "x^" << exponent1 - 1 << " + "
    << exponent2 * coeff2 << "x^" << exponent2 - 1 << " + "
    << exponent3 * coeff3 << "x^" << exponent3 - 1 << endl;
    }
}
 return;
}
