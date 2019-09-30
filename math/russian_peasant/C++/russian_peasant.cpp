#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
#define pb push_back
#define f first
#define sc(n) scanf("%d",&n)
#define scl(n) scanf("%lld",&n)
#define pr(n) printf("%d",n)
#define prl(n) printf("%lld",n)
#define nl printf("\n")
#define fast_io ios_base::sync_with_stdio(false);cin.tie(NULL)

ll mul(ll u,ll v)
{
    ll s=0;
    while(v>0)
    {
        if(v&1)
            s=(s+u);
        u=(u*2);
        v=v>>1;
    }
    return s;
}

int main()
{
	ll i,j;
	cout<<"Enter two numbers to multiply : ";
	cin>>i>>j;
	cout<<mul(i,j)<<endl;
	return 0;
}