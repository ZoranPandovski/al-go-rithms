// C++ Implementation of 2d Max Subrectangle Problem. Complexity: O(n^3)
#include <bits/stdc++.h>
#define fi first
#define se second
#define pb push_back
#define mp make_pair
#define MOD 1000000007
#define pii pair<int,int>
#define LL long long
using namespace std;

int main () {
    //clock_t start = clock();
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int r,c;    // row and col of matrix
    cin >> r >> c;
    int a[r+5][c+5];
    memset (a,0,sizeof(a));
    for (int i=1;i<=r;i++) {
        for (int j=1;j<=c;j++) {
            cin >> a[i][j];
        }
    }

    // prefix sum all columns
    for (int i=1;i<=r;i++) {
        for (int j=1;j<=c;j++) {
            a[i][j]+=a[i-1][j];
        }
    }
    int ans=0;

    for (int i=1;i<=r;i++) {
        for (int j=i;j<=r;j++) {

            // This array contains the sum of all numbers from row i to j
            int sums[r+5];
            for (int k=1;k<=c;k++) {
                sums[k] = a[j][k]-a[i-1][k];
            }
            
            // kadane's algorithm
            int maxSum = 0, curSum=0;
            for (int k=1;k<=c;k++) {
                curSum += sums[k];
                if (curSum<0) curSum=0; 
                maxSum = max(maxSum, curSum);
            }
            ans=max(ans,maxSum);
        }
    }

    cout << ans << endl;

    //cerr << fixed << setprecision(3) << (clock()-start)*1./CLOCKS_PER_SEC << endl;
    return 0;
}