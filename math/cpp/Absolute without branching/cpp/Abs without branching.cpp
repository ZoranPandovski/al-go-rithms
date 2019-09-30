/*
    Computing an integer absolute value (abs) without branching :
    ------------------
    Used to return the absolute value of a given integer without the use of the built in abs() function or any branching techniques.
    
    Time complexity
    ---------------
    O(1)
    
    Space complexity
    ----------------
    O(1).
*/

#include <iostream>
using namespace std;

int abs_without_branching(int x) {
  int sign = x >> 31;
  return ( sign + x ) ^ sign ; 
}
