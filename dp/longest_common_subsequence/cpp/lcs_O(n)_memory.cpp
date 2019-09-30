//Longest Common Subsequence with O(n ^ 2) complexity and O(n) memory
/* Test:
    In: 5 6
        1 1 2 3 5 1000
        1000 3 5 1 1 2
    Out: 3
*/



#include <bits/stdc++.h>

using namespace std;

int a[100005], b[100005], f[100005];
int n, m;

void process() {
    memset(f, 0, sizeof(f));
    for(int i = 1; i <= m; ++i) {
        int u = 0;
        for(int j = 1; j <= n; ++j) {
            if (a[i] == b[j] && f[j] < f[u] + 1) f[j] = f[u] + 1;
            else if (f[u] < f[j]) u = j; // find max value of f to update;
        }
    }
    
    //for(int i = 1; i <= n; ++i) cout << f[i] << ' ';
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    cin >> m >> n;
    for(int i = 1; i <= m; ++i) cin >> a[i];
    for(int i = 1; i <= n; ++i) cin >> b[i];

    process();

    cout << *max_element(f + 1, f + n + 1);
    return 0;
}