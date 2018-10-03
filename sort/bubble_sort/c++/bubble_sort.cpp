#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;


void bubble_sort(vector<int> &a) {
    int n = a.size();
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j + i < n - 1; j++) {
            if (a[j] > a[j + 1]) {
                swap(a[j], a[j + 1]);
            }
        }
    }
}

int main() {
    int n;
    cout << "Enter size of array: ";
    cin >> n;
    vector<int> arr(n);
    cout << "Enter elements in array:\n";
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    bubble_sort(arr);
    cout << "Sorted array:\n";
    for (int i = 0; i < n; i++) {
        cout << a[i] << ' ';
    }
    cout <
