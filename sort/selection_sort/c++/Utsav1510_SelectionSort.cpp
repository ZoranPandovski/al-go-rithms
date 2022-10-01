
#include <iostream>
using namespace std;

void SelectionSort(int n, int arr[]) {

    for (int i = 0; i < n; i++) {
        int min = arr[i];
        int loc = i;
        for (int j = i + 1; j < n; j++) {
            if (arr[j] < min) {
                min = arr[j];
                loc = j;
            }

        }
        //swap(i, loc,arr);
        int temp = arr[i];
        arr[i] = arr[loc];
        arr[loc] = temp;
    }
}
//void swap(int i ,int loc, int arr) {
  //  int temp = arr[i];
    //arr[i] = arr[loc];
    //arr[loc] = temp;



//}
int main()
{

    int arr[] = { 5,4,3,2,3,1,2,2,3123,123,123 };
    int n = sizeof(arr) / sizeof(arr[0]);
    cout << n << endl;
    SelectionSort(n, arr);
    for (int i = 0; i < n; i++) {
        cout << arr[i] << ",";
    }
    return 0;
}
