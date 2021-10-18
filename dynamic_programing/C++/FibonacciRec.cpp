#include <iostream>
#include<algorithm>
#include<unordered_map>
using namespace std;

long long Fib(int n,unordered_map<int,long long>& m)
{
    long long ans;
    if(n<=1) return n;
    else if(m.find(n)!=m.end()) return m[n];
    else
    {
        m[n]=Fib(n-1,m)+Fib(n-2,m);
    }
    return m[n];
}

int main()
{
    int t;
    cin>>t;

    while(t--)
    {
        int n;
        cin>>n;
        unordered_map<int,long long> m,l;
        cout<<Fib(n,m)<<endl;
    }

    return 0;
}
