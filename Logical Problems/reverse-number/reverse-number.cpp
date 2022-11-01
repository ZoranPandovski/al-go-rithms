#include <bits/stdc++.h>

using namespace std;
/* Iterative function to reverse digits of num*/
int reverseDigits(int num)
{
	int rev_num = 0;
	while (num > 0) {
		rev_num = rev_num * 10 + num % 10;
		num /=10;
	}
	return rev_num;
}

/*Driver program to test reverseDigits*/
int main()
{
	int num = 4562;
	cout << "Reverse of no. is " << reverseDigits(num);
	getchar();
	return 0;
}

// This code is contributed
// by Akanksha Rai(Abby_akku)
