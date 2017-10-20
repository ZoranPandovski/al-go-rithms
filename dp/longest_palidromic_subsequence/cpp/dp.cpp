#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    int arr[n];
    for (int i=0; i<n; i++)
        cin >> arr[i];
    int lps[n][n];
    for (int i=0; i<n; i++)
        for (int j=0; j<n; j++)
            lps[i][j] = 0;    
    for (int i=0; i<n; i++)
        lps[i][i] = 1;
    for (int i=n-2; i>=0; i--) {
        for (int j=i+1; j<n; j++) {
            if (arr[i] == arr[j]) {
                lps[i][j] = 2 + lps[i+1][j-1];
            }
            else {
                lps[i][j] = max (lps[i+1][j], lps[i][j-1]);
            }
        }
    }
    cout << lps[0][n-1];
    return 0;
}
