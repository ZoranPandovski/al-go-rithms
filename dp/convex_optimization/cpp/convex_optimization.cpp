#include<bits/stdc++.h>

typedef long long LL;  //Attention!!
using namespace std;

#define fillchar(a, x) memset(a, x, sizeof(a))
#define MP make_pair
#define PB push_back
#define endl '\n'

const int MOD = 1000000007;

struct Line
{//Y = AX + C;
LL M;
LL B;
};

LL Xint(Line &a,Line &b)
{
return (a.B-b.B)/(b.M-a.M);
}

bool uselessb(Line &a,Line &b,Line &c)
{
 return Xint(a,c) < Xint(a,b);
}

//pointer holds current best position in envelope for current x It will always move to right
//as we are making it monotonic by removing useless lines we never hurt ourselves by moving to right

LL pointer;
vector <Line> E;  //Estands for fucking envelope

void add(LL slope,LL constant)
{
Line tmp = {slope,constant};
E.PB(tmp);
LL sz;
while(true)
		{
		sz = E.size();
		if(E.size()<3 || (!uselessb(E[sz-3],E[sz-2],E[sz-1])))	
			{
			break;		
			}
		 
		E.erase(E.end()-2);	
		}
}

LL Yvalue(LL xx,Line &a)
{
return a.M*xx + a.B;
}


LL query(LL xx)
{//We need lowest point in slope increasing hull
if(pointer>E.size())
	pointer = E.size()-1;	
while(pointer+1<E.size() && Yvalue(xx,E[pointer])>Yvalue(xx,E[pointer+1]))
		pointer++;
return Yvalue(xx,E[pointer]);
}

//for this question
const int N = 1e5 + 5;
LL dp[N];

int main()
{
ios_base::sync_with_stdio(0); 
cout.precision(15);
cout.setf(ios::fixed);

int n,m,i,j;
cin>>n;

vector <LL> he(n),be(n);

for(i=0;i<n;i++)
	cin>>he[i];

for(i=0;i<n;i++)
	cin>>be[i];

dp[0] = 0;
add(be[0],dp[0]);

for(i=1;i<n;i++)
	{
	dp[i] = query(he[i]);	
	add(be[i],dp[i]);	
	}

/*
for(i=0;i<n;i++)
	cout<<dp[i]<<' ';
cout<<endl;
*/
cout<<dp[n-1]<<endl;

}
