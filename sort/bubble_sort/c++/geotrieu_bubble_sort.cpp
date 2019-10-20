//An int array name arr is sorted from lowest to highest and outputed.
#include <iostream>

using namespace std;
int main() {
  int arr[5] = {8, 5, 1, 6, 9};
  size_t S = sizeof(arr)/sizeof(arr[0]);
  for (int i = 0; i < S - 1; i++) {
    for (int j = 0; j < S - 1; j++) {
      if (arr[j] > arr[j + 1])
        swap(arr[j], arr[j + 1]);
    }
  }

  //OUTPUT
  for (int i = 0; i < S; i++) {
    cout << arr[i] << endl;
  }
}