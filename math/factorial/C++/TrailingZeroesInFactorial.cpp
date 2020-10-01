/*Given an integer n, return the number of trailing zeroes in n!.
Note: Your solution should be in logarithmic time complexity.
Example :
n = 5
n! = 120 
Number of trailing zeros = 1
So, return 1*/
#include <bits/stdc++.h>

using namespace std;

int main()
{
	int A,x;
	cout << "Enter a number : ";
	cin >> A;
	cout <<endl;
	int count=0;
	int div=5;
	x=A;
	
	while(x/div > 0)
	{
		count = count + (x/div);
		div=div*5;
		x=A;
	}
	cout << "number of trailing zeroes in " << A <<"! = ";
	cout << count;
	return 0;
}
