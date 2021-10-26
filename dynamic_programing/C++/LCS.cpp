#include <iostream>
#include<algorithm>
#include<unordered_map>
using namespace std;

long long LCS(string s,string r,int n,int m)
{
    if(n==0 ||m==0) return 0;
    else if(s[n-1]==r[m-1]) return LCS(s,r,n-1,m-1)+1;
    else return max(LCS(s,r,n-1,m),LCS(s,r,n,m-1));
}

int main()
{
    int t;
    cin>>t;

    while(t--)
    {
        string s,r;
        cin>>s>>r;
        cout<<LCS(s,r,s.length(),r.length())<<endl;
    }

    return 0;
}
