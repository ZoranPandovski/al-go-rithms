#include<iostream>
#include<algorithm>
using namespace std;
typedef long long ll;
#define mod 1000000007


int main()
 {
	//code
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    ll t;
    cin>>t;
    
    while(t--)
    {
        ll n;
        cin>>n;
        ll a[n][n],odds=0;
        for(int i=0;i<n;i++)
        {
            ll c=0;
            for(int j=0;j<n;++j)
            {
                cin>>a[i][j];
                if(a[i][j]==1) c++;
            }
            if(c%2==1) odds++;
        }
        if(odds==2) cout<<1<<endl;
        else cout<<0<<endl;
    }
    
	return 0;
}