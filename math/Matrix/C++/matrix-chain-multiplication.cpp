#include<bits/stdc++.h>
#define init(arr,val) memset(arr,val,sizeof(arr))
#define loop(i,a,b) for(int i=a;i<b;i++)
using namespace std;

int m[100][100], s[100][100];

void print_optimal_parens(int i, int j) {
    if(i == j)
        cout<<(char)(65+i);
    else {
        cout<<"(";
        print_optimal_parens(i, s[i][j]);
        print_optimal_parens(s[i][j]+1, j);
        cout<<")";
    }
}

int main()
    {
    int n, a, b;
    cout<<"Enter No. of Matrices: ";
    cin>>n;
    int p[n+10] = {0};
    cout<<"\n";
    loop(i, 0, n) {
        cout<<"Enter size of Matrix "<<(char)(65+i)<<": ";
        cin>>a>>b;
        if(i == 0) {
            p[0] = a;
            p[1] = b;
        } else {
            if(p[i] != a) {
                cout<<"\n\nNot Feasible.";
                exit(0);
            } else {
                p[i+1] = b;
            }
        }
    }

    // // print Array p
    // cout<<"\n\np -> ";
    // loop(i, 0, n+1)
    //     cout<<p[i]<<" ";

    init(m, -1);
    init(s, -1);
    loop(i, 0, n)
        m[i][i] = 0;
    
    loop(l, 1, n) {
        loop(i, 0, n-l) {
            int j = i+l;
            // cout<<i<<" "<<j<<"\n";
            m[i][j] = INT_MAX;
            loop(k, i, j) {
                int q = m[i][k] + m[k+1][j] + (p[i]*p[k+1]*p[j+1]);
                if(q < m[i][j]) {
                    m[i][j] = q;
                    s[i][j] = k;
                }
            }
        }
    }

    // Printing Matix m and s
    cout<<"\n\nMatrix m:\n";
    loop(i, 0, n) {
        loop(j, 0, n) {
            if(m[i][j] == -1)
                cout<<"-\t";
            else
                cout<<m[i][j]<<"\t";
        }
        cout<<"\n";
    }
    cout<<"\n\nMatrix s:\n";
    loop(i, 0, n) {
        loop(j, 0, n) {
            if(s[i][j] == -1)
                cout<<"-\t";
            else
                cout<<s[i][j]<<"\t";
        }
        cout<<"\n";
    }

    cout<<"\n\nAns: ";
    print_optimal_parens(0, n-1);
    return 0;
    }
