// This is an implementation to test whether a number is perfect or not.


#include <iostream>
using namespace std;

bool isPerfect(int testNum)
{
  int perfectSum = 0;
  for (int i=1;i<testNum;i++){
    if(testNum%i == 0) {
      perfectSum = perfectSum + i;
    }
  }
  if (perfectSum == testNum){
    return true;
  }
  else 
    return false;
}

int main() {
  int numToTest = 0;
  cout << "What number do you want to test for perfection? ";
  cin >> numToTest;
  if (isPerfect(numToTest)) {
    cout << "\n" << numToTest << " is a perfect number!" << endl;
  } else {
    cout << "\n" << numToTest << " is not a perfect number..." << endl;
  }
  return 0;
}  
