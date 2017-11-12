// Program for longest common subsequence in c++
#include<bits/stdc++.h>
using namespace std;
int main()
{
	int n,m;
	char s[10000];                      //two strings which we want to compare and find longest subsequence
	char c[10000];
	cin >> n >> m;                     // Length of two strings
	cin >> s;						
	cin >> c;
	int a[n+1][m+1];
	for(int i=0;i<=n;i++)
	{
		for(int j=0;j<=m;j++)
		{
			if(i==0 || j==0)
			{
				a[i][j]=0;
			}
			else if(s[i-1]==c[j-1])
			{
				a[i][j]=a[i-1][j-1]+1;
			}
			else 
			{
				a[i][j]=max(a[i-1][j],a[i][j-1]);
			}
		}
	}
	cout << a[n][m] << endl;     // print length of longest common subsequence
	return 0;
}

