// C++ program to find n'th Ugly number 
# include<bits/stdc++.h> 
using namespace std; 
#define ull unsigned long long 


ull getNthUglyNo(ull n) 
{ 
	ull ugly[n]; // To store ugly numbers 
	ull i2 = 0, i3 = 0, i5 = 0; 
	ull next_multiple_of_2 = 2; 
	ull next_multiple_of_3 = 3; 
	ull next_multiple_of_5 = 5; 
	ull next_ugly_no = 1; 

	ugly[0] = 1; 
	for (ull i=1; i<n; i++) 
	{ 
	next_ugly_no = min(next_multiple_of_2, 
						min(next_multiple_of_3, 
							next_multiple_of_5)); 
	ugly[i] = next_ugly_no; 
	if (next_ugly_no == next_multiple_of_2) 
	{ 
		i2 = i2+1; 
		next_multiple_of_2 = ugly[i2]*2; 
	} 
	if (next_ugly_no == next_multiple_of_3) 
	{ 
		i3 = i3+1; 
		next_multiple_of_3 = ugly[i3]*3; 
	} 
	if (next_ugly_no == next_multiple_of_5) 
	{ 
		i5 = i5+1; 
		next_multiple_of_5 = ugly[i5]*5; 
	} 
	}
	
	return next_ugly_no; 
} 

int main() 
{ 
	ull n;
	cin>>n;
	cout << getNthUglyNo(n); 
	return 0; 
} 
