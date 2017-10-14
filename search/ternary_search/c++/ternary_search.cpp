#include <iostream>
using namespace std;

/*
 * returns the index of the maximum element in ar
 */
int ternary_search(int ar[], int n) {
    int start = 0, end = n - 1;
    while (start < end) {
        int mid1 = start + (end - start) / 3;
        int mid2 = end - (end - start) / 3;
        if (ar[mid1] <= ar[mid2]) {
            start = mid1 + 1;
        } else {
            end = mid2 - 1;
        }
    }
    return start;
}

int main() {
    freopen("tests.txt", "r", stdin);
    int num_tests;
    cin >> num_tests;

    for (int t = 0; t < num_tests; t++){
        int n;
        cin >> n;
        int ar[n];
        for (int i = 0; i < n; i++){
            cin >> ar[i];
        }
        cout << "Test#" << t+1 << ": " << ar[ternary_search(ar, n)] << endl;
    }
    return 0;
}

