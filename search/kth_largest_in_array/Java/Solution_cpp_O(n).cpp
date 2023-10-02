#include<bits/stdc++.h>
#define ll long long
using namespace std;

int partition(ll a[],int l,int r){
    int k=l+rand()%(r-l+1),i=l;
    swap(a[l],a[k]);
    ll key=a[l];
    for(int j=l+1;j<=r;j++){
        if(a[j]<=key){
            i++;
            swap(a[i],a[j]);
        }
    }
    swap(a[l],a[i]);
    return i;
}

ll kth_largest(ll a[],ll l,ll r,ll k){
    if(k>r-l+1||k<=0) return LLONG_MAX;
    int p=partition(a,l,r);
    if(p==r-k+1) return a[p];
    if(p>r-k+1) return kth_largest(a,l,p-1,k-r+p-1);
    return kth_largest(a,p+1,r,k);
}

int main(){
    int n,k;
    cin>>n>>k;
    srand(time_t(NULL));
    ll a[n];
    for(int i=0;i<n;i++) cin>>a[i];
    ll ans=kth_largest(a,0,n-1,k);
    if(ans==LLONG_MAX) cout<<"No Kth largest element\n";
    else cout<<ans<<'\n';
    return 0;
}
