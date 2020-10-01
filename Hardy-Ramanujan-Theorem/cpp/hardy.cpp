
// CPP program to count all prime factors 
#include <iostream>
#include<cstdlib>
#include<math.h>
using namespace std; 
  
// A function to count prime factors of 
// a given number n 
int exactPrimeFactorCount(int n) 
{ 
    int count = 0; 
  
    if (n % 2 == 0) { 
        count++; 
        while (n % 2 == 0) 
            n = n / 2; 
    } 
  
    // n must be odd at this point. So we can skip 
    // one element (Note i = i +2) 
    for (int i = 3; i <= sqrt(n); i = i + 2) { 
        if (n % i == 0) { 
            count++; 
            while (n % i == 0) 
                n = n / i; 
        } 
    } 
  
    // This condition is to handle the case when n 
    // is a prime number greater than 2 
    if (n > 2) 
        count++; 
    return count; 
} 
  
// driver function 
int main() 
{ 
    int n = 51242183; 
    cout << "The number of distinct prime factors is/are "
         << exactPrimeFactorCount(n) << endl; 
    cout << "The value of log(log(n)) is "
         << log(log(n)) << endl; 
    return 0; 
} 