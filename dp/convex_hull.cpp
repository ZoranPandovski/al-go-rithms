#include<bits/stdc++.h>
 
typedef long long LL;  //Attention!!
using namespace std;
 
#define fillchar(a, x) memset(a, x, sizeof(a))
#define MP make_pair
#define PB push_back
#define endl '\n'
 
const int M = 1000000007;
 
struct pt
{
LL xx;LL yy;
 
bool operator<(const pt &b)
const {
		return (xx < b.xx);
    	};
 
pt operator + (pt &b)
	{
	pt c;
	c.xx = xx + b.xx;
	c.yy = yy + b.yy;
	return c;
	};
 
pt operator - (pt &b)
	{
	pt c;
	c.xx = xx - b.xx;
	c.yy = yy - b.yy;
	return c;
	};
 
};
 
double dis(pt a,pt b)
{
return sqrt((a.xx-b.xx)*(a.xx-b.xx) + (a.yy-b.yy)*(a.yy-b.yy));
}
 
 
vector <pt> v,ch;
pt pivot;
 
LL ccw(pt a,pt b,pt c)
{
if((c.xx-b.xx)*(b.yy-a.yy)-(c.yy-b.yy)*(b.xx-a.xx)<0)
	return 1;
else if((c.xx-b.xx)*(b.yy-a.yy)-(c.yy-b.yy)*(b.xx-a.xx)>0)
	return -1;
else
	return 0;
}
 
LL Area(pt a,pt b,pt c)  //this actually give area *2
{
return abs((c.xx-b.xx)*(b.yy-a.yy)-(c.yy-b.yy)*(b.xx-a.xx)); 
}
 
bool myfun(const pt &a,const pt &b)
{
return a.yy < b.yy;
}
 
bool myfun2(const pt &a,const pt &b)
{
int k=ccw(a,pivot,b);
 
if(k==-1)   //right turn means b makes bigger angle
	return true;
else if(k==1)
	return false;
else if(k==0)
	return a.xx<b.xx;
}
 
pt top2(stack <pt> &s)
{
	pt p,q;
	p=s.top();
	s.pop();
	q=s.top();
	s.push(p);
	return q;
}
 
void convex_hull()
{
sort(v.begin(),v.end());
sort(v.begin(),v.end(),myfun);
pivot=v[0];
sort(v.begin()+1,v.end(),myfun2);
stack <pt> s;
pt temp;
 
s.push(v[0]);
s.push(v[1]);
 
for(LL i=2;i<v.size();i++)
	{
				
	while(ccw(top2(s),s.top(),v[i])!=1)   //if I pass it as reference it will be difficult
		s.pop();
	
	s.push(v[i]);		
	}
 
while(!s.empty())
	{ch.PB(s.top());
	s.pop();	
	}
}
 
 
 
 
int main()
{
ios_base::sync_with_stdio(0); cout.precision(15);cout.setf(ios::fixed);
LL n,i,j,m,s;
 
cin>>n;
 
v.resize(n);
 
for(i=0;i<n;i++)
	cin>>v[i].xx>>v[i].yy;
 
convex_hull();
 
n = ch.size();
 
double A = 0;
 
for(i=0;i<n;i++)
	A += (dis(ch[i],ch[(i+1)%n]));
 
LL ans = A;
 
cout<<ans<<endl;
 
}
//khali t-shirt ke liye aaye hain
