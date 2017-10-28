#include <iostream>
#include <math.h>
#include <string.h>
#include <cstring>
using namespace std;
// some global variables to help save space - we'll be using these a lot.
// coeff = coefficient
double coeff1;
double coeff2;
double coeff3;
double exponent1;
double exponent2;
double exponent3;
void fun_integral()
{
 string num_coeff2;
 cout.precision(10);
 while (num_coeff2 != "4")// keep user in this menu until they leave.
{
 cout << "\n\n**********************"
    << "\n\n*INTEGRALS*"
    << "\n\nMonomial or polynomial?"
    << "\n 1. 1 coefficient"
    << "\n 2. 2 coefficients"
    << "\n 3. 3 coefficients"
    << "\n 4. Return to previous screen"
    << "\n\nEnter choice: ";
 cin >> num_coeff2;

 if (num_coeff2 == "1")
    {
     cout << "\n\nEnter value of coefficient: ";
     cin >> coeff1;
     cout << "\nEnter value of exponent: ";
     cin >> exponent1;
     // here we're showing the user what they entered,
     // and then the resulting integration of that.
     // formula: x^n dx = x^(n+1) / (n+1) + C
     // if they enter -1 as n, it won't give an error, but
     // they ought to know it's incorrect.
     cout << "\n\nYou entered: "
    << coeff1 << "x^" << exponent1
    << "\n\nYour new integral is: ("
    << coeff1 << "/" << exponent1 + 1
    << ")x^" << exponent1 + 1 << endl;
    }
 else if (num_coeff2 == "2")
    {
     cout << "\n\nEnter value of coefficient 1: ";
     cin >> coeff1;
     cout << "\nEnter value of exponent 1: ";
     cin >> exponent1;
     cout << "\n\nEnter value of coefficient 2: ";
     cin >> coeff2;
     cout << "\nEnter value of exponent 2: ";
     cin >> exponent2;
     cout << "\n\nYou entered: "
    << coeff1 << "x^" << exponent1 << " + "
    << coeff2 << "x^" << exponent2
    << "\n\nYour new integral is: ("
    << coeff1 << "/" << exponent1 + 1
    << ")x^" << exponent1 + 1 << " + ("
    << coeff2 << "/" << exponent2 + 1
    << ")x^" << exponent2 + 1 << endl;
    }
 else if (num_coeff2 == "3")
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
     cout << "\n\nYou entered: "
    << coeff1 << "x^" << exponent1 << " + "
    << coeff2 << "x^" << exponent2 << " + "
    << coeff3 << "x^" << exponent3
    << "\n\nYour new integral is: ("
    << coeff1 << "/" << exponent1 + 1
    << ")x^" << exponent1 + 1 << " + ("
    << coeff2 << "/" << exponent2 + 1
    << ")x^" << exponent2 + 1 << " + ("
    << coeff3 << "/" << exponent3 + 1
    << ")x^" << exponent3 + 1 << endl;
    }
}
 return;
}
int main()
{
     fun_integral();
 return 0;
}

