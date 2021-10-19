#include<iostream>
#include<algorithm>
using namespace std;
typedef long long ll;
#define mod 1000000007

ll floodFill(vector<vector<ll>> &a,ll x, ll y,ll k,ll curPix)
{
    a[x][y]=k;
    if(x>0 && a[x-1][y]==curPix)
    {
        floodFill(a,x-1,y,k,curPix);
    }
    if(x<a.size()-1 && a[x+1][y]==curPix)
    {
        floodFill(a,x+1,y,k,curPix);
    }
    if(y>0 && a[x][y-1]==curPix)
    {
        floodFill(a,x,y-1,k,curPix);
    }
    if(y<a[0].size()-1 && a[x][y+1]==curPix)
    {
        floodFill(a,x,y+1,k,curPix);
    }
    
}

int main()
 {
	//code
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    ll t;
    cin>>t;
    
    while(t--)
    {
        ll n,m;
        cin>>n>>m;
        
        vector<vector<ll>> a(n);
        for(int i=0;i<n;++i)
        {
            a[i].resize(m);
            for(int j=0;j<m;++j)
            {
                cin>>a[i][j];
            }
        }
        ll x,y,k;
        cin>>x>>y>>k;
        ll curpix=a[x][y];
        
        floodFill(a,x,y,k,curpix);
        for(int i=0;i<n;++i)
        {
            for(int j=0;j<m;++j)
            {
                cout<<a[i][j]<<" ";
            }
        }
        cout<<endl;
        
    }
    
	return 0;
}