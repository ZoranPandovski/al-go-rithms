// A simple (but inefficient) prime tester that uses no complex functions

// INCLUDES
#include <iostream>

using namespace std;

// VARIABLES
int testNumber = 0;  // Stores the number that will be tested to see if it is prime

int main ()
{
  // Get Input
  cout << "Please enter a number to test if it is prime:" << endl;
  cin >> testNumber;
  
  bool prime = true;
  
  if (testNumber == 1 || testNumber == 2) // 1 and 2 are prime numbers that won't run through the for loop
  {
    prime;
  } 

  for (int i = 2; i < testNumber; i++) {  // This for loop goes trhough every value of i, from 2 to testNumber
      if (testNumber % i == 0) {  // The testNumber is then divided into i, and if it divides evenly, with no remainder, it continues testing numbers
        prime = false; // This function simply stops the program where it is, and forces it to restart the for loop, at the next iteration of i
        break;
      }
    }
 
  if (prime) cout << "That number is prime :)" << endl;
      else cout << "That number is not prime :(" << endl;
 
