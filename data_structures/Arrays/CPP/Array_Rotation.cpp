#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <sstream>
#include <queue>
#include <deque>
#include <bitset>
#include <iterator>
#include <list>
#include <stack>
#include <map>
#include <set>
#include <functional>
#include <numeric>
#include <utility>
#include <limits>
#include <time.h>
#include <math.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h>

using namespace std;
using ll = long long;
using vi = vector<ll>;
using vii = vector< vector <ll>>;
#define pb emplace_back
#define rsz resize
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
#define loop(i,n) for(ll i = 0;i<n;i++)
using pi = pair<int,int>;
#define mp make_pair
#define endl "\n"
ll mod = 1000000007;
ll MOD = mod;

 
 
int main() {
   
    ios::sync_with_stdio(0);
    cin.tie(0);

        int n;
        cin >> n;
        ll sum = 0;
        ll temp;
        loop(i, n) {
            cin >> temp;
            sum += temp;
           
        }
        sum %= MOD;
        if (sum < 0) sum += MOD;
        
        int q;
        cin >> q;
        while(q--){
            int useless;
            cin >> useless;
            sum *= 2;
            if (sum >= MOD) sum -= MOD;
            cout << sum << endl;
        }
        
        
    
        
  
 
    return 0;
}
