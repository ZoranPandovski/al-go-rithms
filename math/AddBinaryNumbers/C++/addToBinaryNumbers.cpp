#include <bits/stdc++.h>
using namespace std;

string addBinNum(string a, string b)
{
	string result = "";
	int sum = 0;

	int i = a.size()-1, j = b.size()-1;
	while (i>=0 || j>=0 || sum==1)
	{
		sum += ((i >= 0)? a[i]-48: 0);
		sum += ((j >= 0)? b[j]-48: 0);
		result = char(sum % 2 + 48) + result;
		sum /= 2;
		i--; 
		j--;
	}
	return result;
}

int main()
{
	string a,b;
	cout<<"Enter two binary numbers : ";
	cin>>a>>b;
	cout << addBinNum(a, b) << endl;
	return 0;
}
