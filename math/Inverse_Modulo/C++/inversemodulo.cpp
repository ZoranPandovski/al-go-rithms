#include <bits/stdc++.h>
using namespace std;

const int MOD = 37;

// Power function in O(log n) time
int power_of(int num, int p)
{
	int answer = 1;

	while(p!=0)
	{
		if(p%2 == 1)
		{
			answer = answer*num;
			answer = answer%MOD;
		}
		num = num*num;
		num = num%MOD;
		p = p/2;
	}

	return answer;
}

//Inverse modulo function
int inverse_modulo(int n)
{
	return power_of(n,MOD-2);
}

int main()
{
	int n,p,newnum,div,ans;

	cout<<"Enter the number: ";
	cin>>n;

	cout<<"Enter the power: ";
	cin>>p;

	cout<<"Enter a valid divisor: ";
	cin>>div;

	newnum = power_of(n,p);

	ans = newnum * inverse_modulo(div);
	ans = ans%MOD;

	cout<<ans;
}
