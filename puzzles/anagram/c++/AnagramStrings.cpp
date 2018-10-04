#include<bits/stdc++.h>
using namespace std;

int main()
{
    cout<<"\nEnter two word to check if they are Anagrams:\n";
    string str1, str2;
    cin>>str1>>str2;
    reverse(str1.begin(), str1.end());
    if(str1==str2)
        cout<<"\nThe two words are Anagrams.\n";
    else
        cout<<"\nThe two words are not Anagrams.\n";
    
    return 0;
}
