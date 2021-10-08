// C++ program to print a consecutive sequence
// to express N if possible.
#include <bits/stdc++.h>
using namespace std;

// Print consecutive numbers from
// last to first
void printConsecutive(int last, int first)
{
	cout << first++;
	for (int x = first; x<= last; x++)
		cout << " + " << x;
}

void findConsecutive(int N)
{
	for (int last=1; last<N; last++)
	{
		for (int first=0; first<last; first++)
		{
			if (2*N == (last-first)*(last+first+1))
			{
				cout << N << " = ";
				printConsecutive(last, first+1);
				return;
			}
		}
	}
	cout << "-1";
}

// Driver code
int main()
{
	int n = 12;
	findConsecutive(n);
	return 0;
}
