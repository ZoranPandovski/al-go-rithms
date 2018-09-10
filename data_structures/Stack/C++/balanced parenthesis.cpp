#include <iostream>
#include <stack>
#include <string>
using namespace std;
bool check(char x, char y)
{
	if ((x=='(' && y==')') || (x=='{' && y=='}') || (x=='[' && y==']') || (x=='<' && y=='>'))
	{
		return true;
	}
	else
	{
		return false;
	}
}

bool checkbalancedparenthesis(string s)
{
	stack<char> st;
	int top=-1;
	int l=s.length();
	for(int i=0;i<l;i++)
	{
		if(s[i]=='(' || s[i]=='{' || s[i]=='[')
		{
		st.push(s[i]);
		top=top+1;
		}
		else if(s[i]==')' || s[i]=='}' || s[i]==']')
		{
			if(top==-1 || check(st.top(),s[i])==false)
			{
				return false;
			}
			else
			{
			st.pop();
			top=top-1;
			}
		}
	}
	if(top==-1)
	return true;
	else
	return false;
}
int main() 
{
	// your code goes here
	int test;
	cin>>test;
	while(test-->0)
	{
	string s;
	cin>>s;
	if(checkbalancedparenthesis(s)==true)
	cout<<"BALANCED"<<endl;
	else
	cout<<"NOT BALANCED"<<endl;
	}
	return 0;
}