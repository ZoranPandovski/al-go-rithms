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
  
  for (int i = 2; i < testNumber; i++) {  // This for loop goes trhough every value of i, from 2 to testNumber
    if (testNumber % i != 0) {  // The testNumber is then divided into i, and if it divides evenly, with no remainder, it continues testing numbers
      continue; // This function simply stops the program where it is, and forces it to restart the for loop, at the next iteration of i
    }
    else {
      cout << "That number is not Prime :(" << endl;  // If the if statement above fails, this message will be printed, and the program exited
      return 0;
    }
    cout << "That number is Prime :)" << endl;  // If the entire for loop is played through, with the if statement triggering everytime, the number is prime
}
