#include<bits/stdc++.h>
#define init(arr,val) memset(arr,val,sizeof(arr))
#define loop(i,a,b) for(int i=a;i<b;i++)
using namespace std;

string s1, s2;
int a[100][100];
char b[100][100];

void print(int i, int j) {
    if(i == 0 || j == 0)
        return;
    if(b[i][j] == 'x') {
        print(i-1, j-1);
        cout<<s1[i-1];
    } else if(b[i][j] == 'u') 
        print(i-1, j);
    else
        print(i, j-1);
}

int main() {
    cin>>s1>>s2;
    int m = s1.size(), n = s2.size();
    loop(i, 0, m+1)
        a[i][0] = 0;
    loop(j, 0, n+1)
        a[0][j] = 0;

    loop(i, 1, m+1) {
        loop(j, 1, n+1) {
            if(s1[i-1] == s2[j-1]) {
                a[i][j] = a[i-1][j-1] + 1;
                b[i][j] = 'x';
            } else if(a[i-1][j] >= b[i][j-1]) {
                a[i][j] = a[i-1][j];
                b[i][j] = 'u';
            } else {
                a[i][j] = a[i][j-1];
                b[i][j] = 'l';
            }
        }
    }

    print(m, n);
    return 0;
}