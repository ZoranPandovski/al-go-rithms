#include<bits/stdc++.h>
#define assn(n,a,b) assert(n<=b && n>=a)
using namespace std;
#define pb push_back
#define mp make_pair
#define clr(x) x.clear()
#define sz(x) ((int)(x).size())
#define F first
#define S second
#define REP(i,a,b) for(i=a;i<b;i++)
#define rep(i,b) for(i=0;i<b;i++)
#define rep1(i,b) for(i=1;i<=b;i++)
#define pdn(n) printf("%d\n",n)
#define sl(n) scanf("%lld",&n)
#define sd(n) scanf("%d",&n)
#define pn printf("\n")
typedef pair<int,int> PII;
typedef vector<PII> VPII;
typedef vector<int> VI;
typedef vector<VI> VVI;
typedef long long LL;
#define MOD 1000000007
LL mpow(LL a, LL n)
{LL ret=1;LL b=a;while(n) {if(n&1)
    ret=(ret*b)%MOD;b=(b*b)%MOD;n>>=1;}
return (LL)ret;}
#define MAXK 100000
#define MAXN 1000000000
int ar[MAXK];
int get(int n, int k){
    int i=0;
    while(i<k and ar[i]<=n)i++;
    return n-i;
}


int segtree[2*MAXK];
int input[MAXK];

void init()
{
    for(int i=0;i<2*MAXK;i++)
    {
        segtree[i] = MAXK+1;
    }
}

void build(int low, int high, int pos)
{
    if(low == high)
    {
        segtree[pos] = input[low]; return;
    }
    else
    {
        int mid = (low+high)/2;
        build(low,mid,2*pos+1);
        build(mid+1,high,2*pos+2);
        segtree[pos] = min(segtree[2*pos+1],segtree[2*pos+2]);
    }
}




int segtree_length(int n)
{
    if( sqrt((log(n))/(log(2))) == floor(sqrt((log(n))/(log(2)))) )
    {
        return 2*n-1;
    }
    else
    {
        return 2*pow(2,floor((log(n))/(log(2)))+1) - 1;
    }
}

int query(int pos, int nodel,int noder, int l, int r)
{
    //no overlap
    if(nodel > r || noder < l)
    {
        return MAXK+1;
    }
    //complete overlap
    if(nodel >= l && noder <= r)
    {
        return segtree[pos];
    }
    //partial overlap
    int mid = (nodel + noder)/2;
    int p1  = query(2*pos+1,nodel,mid,l,r);
    int p2  = query(2*pos+2,mid+1,noder,l,r);
    return min(p1,p2);
}

void update(int pos, int nodel, int noder, int index, int value)
{
    if(nodel == noder)
    {
        input[index] = value;
        segtree[pos] = value;
    }
    else
    {
        int mid = (nodel + noder)/2;
        if(index >= nodel && index <= mid)
        {
            update(2*pos + 1, nodel, mid, index, value);
        }
        else
        {
            update(2*pos + 2, mid+1, noder, index, value);
        }
        segtree[pos] = min(segtree[2*pos+1], segtree[2*pos+2]);
    }
}

int main(){
    init();
    int n;cin>>n;
    for(int i=0;i<n;i++)
    {
        int x;sd(x);input[i] = x;
    }
    build(0,n-1,0);
    /* Print segment tree
    int l = segtree_length(n);
    cout<<"l:"<<l<<"."<<endl;
    for(int i=0;i<l;i++)
    {
        cout<<segtree[i]<<" ";
    }
    */
    cout<<query(0,0,4,1,3)<<endl;
    update(0,0,4,3,1);
    cout<<query(0,0,4,1,3)<<endl;

	return 0;
}