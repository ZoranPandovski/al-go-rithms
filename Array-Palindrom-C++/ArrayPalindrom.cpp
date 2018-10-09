#include <iostream>

template <typename T>
bool isPalindrome(T arrayToCheck[], unsigned int arraySize);

using namespace std;

int main() {
  int arrayToCheck[6] = { 1, 2, 4, 4, 2, 1 };

  cout << boolalpha << isPalindrome(arrayToCheck, 6);

  int tmp;
  cin >> tmp;

  return 0;
}


template <typename T>
bool isPalindrome(T arrayToCheck[], unsigned int arraySize) {
  for (unsigned int i = 0; i < arraySize / 2; i++) {
    if (arrayToCheck[i] != arrayToCheck[arraySize - 1 - i]) {
      return false;
    }
  }

  return true;
}
