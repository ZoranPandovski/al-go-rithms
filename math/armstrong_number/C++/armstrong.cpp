#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;

ll power(int a,int b)
{
	if(b==0)
		return 1;
	if(b%2==0)
		return power(a,b/2)*power(a,b/2); 
	return a*power(a,b/2)*power(a,b/2);
}
int main()
{
	ll x,n,sum=0;
	cout << "Enter a number : ";
	cin >> n;
	ll num = n,c = 0;
	while(n)
		n=n/10,c++;
	n=num;
	while(n)
	{
		x=n%10;
		n=n/10;
		sum+=power(x,c);
	}
	if(sum==num)
		cout<<"Number is an armstrong number"<<endl;
	else
		cout<<"Number is not an armstrong number"<<endl;
	return 0;
}