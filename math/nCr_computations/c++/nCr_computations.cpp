// C++ program to compute value of nCr
#include <bits/stdc++.h>
using namespace std;
 
long int nCr(int n, int r) {
    long int comp = 1;
    // Calculate minimum of r and n - r.
    // Save it into m.
    int m;
    if(n - r > r)
        m = r;
    else 
        m = n - r;
    
    // Final computation = n! / (n - r)! r!     =>      ((n-r+1)* .... *n) / r!         OR      (r* .... *n) / (n-r)!

    for(int i = n; i > (n - m); i--) {
        comp *= i;
    }
    for(int i = 1; i <= m; i++) {
        comp /= i;
    }

    return comp;
}
 
// Driver Program to test above function
int main() {
    int n = 30, r = 10;
    cout<<"nCr ("<<n<<", "<<r<<") = "<<nCr(n, r)<<endl;
    return 0;
}
