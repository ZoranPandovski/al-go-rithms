#include<iostream>
#include<stack>
#include<string>
using namespace std;

bool balancing(char a,char b)
{
    return ((a=='(' && b==')')||(a=='{' && b=='}') || (a=='[' && b==']'));
}
bool isbalanced(string str)
{
    stack<char> s;
    int i;
    for(i=0;i<str.length();i++)
    {
        if(str[i]=='(' || str[i]=='{' || str[i]=='['){
            s.push(str[i]);
        }

        else
        {
            if(s.empty()==true){
                return false;
            }
            else if(balancing(s.top(),str[i])==false)
            {
                return false;

            }
            else{
                s.pop();
            }
        }
    }
    return (s.empty());
}
int main()
{
    string str;
    cin>>str;
    cout<<isbalanced(str);
}
