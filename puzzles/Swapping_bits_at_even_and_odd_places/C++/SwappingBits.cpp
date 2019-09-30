#include<bits/stdc++.h>
using namespace std;

int swapbits(int val)
{
	int val2;
	val2 = ((val & 0xaaaaaaaa) >> 1) | ((val & 0x55555555) <<1);
	return val2;
}
int main()
{
	int a,b;
	cin>>a;
	b = swapbits(a);
	cout<<b<<endl;
	return 0;
}
