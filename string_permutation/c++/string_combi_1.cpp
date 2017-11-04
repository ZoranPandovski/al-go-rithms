/*
	INPUT: ABC
	OUTPUT : 
	A
	AB
	ABC
	AC
	ACB
	B
	BA
	BAC
	BC
	BCA
	C
	CA
	CAB
	CB
	CBA
*/

#include <bits/stdc++.h>
using namespace std;

void helper(vector<char> v,string s,int visited[])
{

	int n = v.size();
	for (int i = 0; i < n; ++i)
	{	
		if(!visited[i] )
		{	
				visited[i] = 1;
				cout<<s+v[i]<<endl;
				helper(v,s+v[i],visited);
			
				visited[i]=0;
		}

	}
	


}

int main()
{
	string a;
	getline(cin,a);
	int n = a.size();
	sort(a.begin(),a.end());
	vector<char> v(a.begin(),a.end());
	int visited[n]={0};
	string s = "";
	helper(v,s,visited);
}

