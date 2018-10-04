//Returns if the input is a Palindrome or not

#include <bits/stdc++.h>
using namespace std;

bool IsPalindrome(const string& str)
{
    if (str.empty())
        return false;

    int l=str.length();
    for(int i=0;i<l/2;i++)
    {
        if(str[i]!=str[l-i-1])
            return false;
    }
   
    return true;
}


bool ispalin(int n)
{
    int a=n,rem,rev=0;
    while(a)
    {
        rev=rev*10;
        rev=rev+(a%10);
        a=a/10;       
    }
    if(rev==n)
        return true;
    else
        return false;      
}

int main()
{

cout << "Enter a number to check if Palindrome\n";
int n;
cin >> n;
if(ispalin(n))
  cout << n << " is a Palindrome\n";
else
  cout << n << " is not a Palindrome\n";


cout << "Enter a string to check if Palindrome\n";
string s;
cin >> s;
if(IsPalindrome(s))
  cout << s << " is a Palindrome\n";
else
  cout << s << " is not a Palindrome\n";
  
  
return 0;
}
