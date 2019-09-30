#include<bits/stdc++.h>
 
typedef int LL;
using namespace std;
const int M = 1000000007;
const int N=400001;
 
LL n;
vector <LL> v;
vector <LL> tree[N];
 
void build(LL x,LL l,LL r)
{	LL m= (l+r) >> 1;

	if(l<r)
	{
		build(2*x,l,m);
		build(2*x+1,m+1,r);
		tree[x].resize(tree[2*x].size()+tree[2*x+1].size());
		merge(tree[2*x].begin(),tree[2*x].end(),tree[2*x+1].begin(),tree[2*x+1].end(),tree[x].begin());
	}
	else
 		tree[x].push_back(v[l]);
}
 
 
LL get(LL x,LL l,LL r,LL ll,LL rr,LL k)
{
	LL m= (l+r) >> 1;
 
	if (ll<=l && r<=rr)
		 return lower_bound(tree[x].begin(),tree[x].end(),k) - tree[x].begin();
	 else if (r<ll || l>rr)
		return 0;
	else
		return get(2*x,l,m,ll,rr,k) + get(2*x+1,m+1,r,ll,rr,k);
}
 
 
LL getl(LL x,LL l,LL r,LL ll,LL rr,LL k)
{
	LL m= (l+r) >> 1;
	vector <LL> :: iterator it; 
	if (ll<=l && r<=rr)
		 {
		 	it= lower_bound(tree[x].begin(),tree[x].end(),k);
		 	if(it!=tree[x].end())
		 		return *it;
		    else
		    	return M;
		 }
 	else if (r<ll || l>rr)
		return M;
	else
		return min(getl(2*x,l,m,ll,rr,k) , getl(2*x+1,m+1,r,ll,rr,k) );
}
 
 
 
 
 
LL getk(LL a,LL b,LL c)
{
LL l=0,h=n-1;
LL m;
 
while(l<h)
{
m=(l+h)>>1;
 
LL d=get(1,0,n-1,a,b,tree[1][m]);
 
//cout<<l<<' '<<h<<' '<<m<<' '<<tree[1][m]<<' '<<d<<endl;
 
if(c>d)
	   l=m+1;
else
		h=m;
}
//cout<<"YO"<<endl;
//cout<<l+1<<' '<<tree[1][l]<<endl;
 
 
return getl(1,0,n-1,a,b,tree[1][l]);
 
}
 
 
int main()
{
LL i,m,a,b,c,A=0;
 
cin>>n>>m;
 
v.resize(n);
 
for(i=0;i<n;i++)
	scanf("%d",&v[i]);
 
build(1,0,n-1);
 
 
 
for(i=0;i<m;i++)
	{
		scanf("%d%d%d",&a,&b,&c);
		a--;b--;c--;
 
		A=getk(a,b,c);
	
		printf("%d\n",A);
	}
 
}
