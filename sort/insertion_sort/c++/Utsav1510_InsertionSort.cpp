
#include <iostream>
using namespace std;

void InsertionSort(int n, int arr[]) {
    for (int i = 1; i < n; i++) {
        int key = arr[i];
        int j = i;
        while (j > 0 && arr[j - 1] > key) {
            arr[j] = arr[j - 1];
            j--;
        }
        arr[j] = key;

    }

}
void display(int arr[],int n) {
    for (int i = 0; i < n; i++) {
        cout << arr[i] << ",";
    }


}


//}
int main()
{

    int arr[] = { 5,4,3,2,3,1,2,2,3123,123,123 };
    int n = sizeof(arr) / sizeof(arr[0]);

    cout << n << endl;
    InsertionSort(n, arr);
    
    display(arr,n);

}

