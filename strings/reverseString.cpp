#include <bits/stdc++.h>
using namespace std;

string revStr(string str)
{
    int len=str.length();
    for(int i=0;i<len/2;i++)
    {
        swap(str[i],str[len-1-i]);
    }
    return str;
}

int main()
{
    
    string s;
    cin>>s;
    string result = revStr(s);
    cout << result << "\n";
    return 0;
}

/*
input:
abcd

output:
dcba
*/
