#include <bits/stdc++.h>
#define ll long long

using namespace std;


int main()
{
    ll n,freq[100005]={0};

    cout<<"Enter length of array - ";
    cin >>n;

    cout<<"Enter elements of arrays - ";
    ll a[n],op[n];
    for(ll i=0;i<n;i++)
    {
        cin >> a[i];
        freq[a[i]]++;
    }

    for(ll i=1;i<100005;i++)
    freq[i] = freq[i]+freq[i-1];

    for(ll i=0;i<n;i++)
    {
        op[freq[a[i]]-1]=a[i];
        freq[a[i]]--;
    }

    for(ll i=0;i<n;i++)
    cout<<op[i]<<" ";

    return 0;
}
