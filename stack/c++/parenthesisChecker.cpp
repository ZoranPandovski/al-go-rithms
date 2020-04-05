/*
by @ritul120

Given an expression string exp. Examine whether the pairs and the orders of “{“,”}”,”(“,”)”,”[“,”]” are correct in exp.
For example, the program should print 'balanced' for exp = “[()]{}{[()()]()}” and 'not balanced' for exp = “[(])”

*/

#include<bits/stdc++.h>
#include<stack>
using namespace std;

bool match(char a,char b)
{
    if(a=='{' && b=='}')  
        return true;
    if(a=='(' && b==')')  
        return true;
    if(a=='[' && b==']')  
        return true;
    return false;
}
bool balanced(string str)
{   int i,n= str.length();
    stack<char> st;
    
    for(i=0;i<n;i++)
    {   if(str[i]=='{' ||str[i]=='(' ||str[i]=='[')
            st.push(str[i]);
        else
        {   char ch;
            if(!st.empty())
            {   ch= st.top();
                st.pop();
            }
            else
                return false;
            if(!match(ch,str[i]))
                return false;
        }
    }
    if(st.empty())
        return true;
    return false;
}

int main() {
	
	    string str;
	    cin>>str;
	    if(balanced(str))
	        cout<<"balanced"<<endl;
	   else
	        cout<<"not balanced"<<endl;
	
	return 0;
}