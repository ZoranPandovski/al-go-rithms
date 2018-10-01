#include<bits/stdc++.h>
using namespace std;

int a[510],n;

int fun(int l,int r){
    if(l==r)
        return a[l];
    int mid = (l+r)/2;
    if(l==r-1)
        return min(a[l],a[r]);
    if(mid==l || a[mid]>=a[r])
        return fun(mid,r);
    else if(mid==r || a[mid]<a[l])
        return fun(l,mid);
}

int main()
{
    int t;
    cin>>t;
    while(t--){
        cin>>n;
        for(int i=0;i<n;i++) cin>>a[i];
        cout<<fun(0,n-1)<<endl;
    }
    return 0;
}
