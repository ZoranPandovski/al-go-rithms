#include <bits/stdc++.h> 
using namespace std; 

vector<int> findPrimeFactors(int n) 
{ 
    vector<int> result; 
    if (n % 2 == 0) { 
        while (n % 2 == 0) 
            n = n / 2; 
        result.push_back(2); 
    } 
  
    for (int i = 3; i <= sqrt(n); i = i + 2) { 
  
        // Check if i is prime factor 
        if (n % i == 0) { 
            while (n % i == 0) 
                n = n / i; 
            result.push_back(i); 
        } 
    } 

    if (n > 2) 
        result.push_back(n); 
    return result; 
} 
  
bool isHoax(int n) 
{  
    vector<int> primefactors = findPrimeFactors(n); 

    if (primefactors[0] == n) 
        return false; 
      
    int sumOfAllPrimeFactors = 0;     
    for (int i = 0; i < primefactors.size(); i++) { 
  
        int primefactors_sum; 
        for (primefactors_sum = 0; primefactors[i] > 0;  
             primefactors_sum += primefactors[i] % 10, primefactors[i] /= 10) 
            ; 
  
        sumOfAllPrimeFactors += primefactors_sum; 
    } 

    int sumOfDigits; 
    for (sumOfDigits = 0; n > 0; sumOfDigits += n % 10, 
                                  n /= 10) 
        ; 
  
    return sumOfDigits == sumOfAllPrimeFactors; 
} 

int main() 
{ 
    int n;
	cin >> n;
    if (isHoax(n)) 
        cout << "YES\n"; 
    else
        cout << "NO\n"; 
    return 0; 
} 