#include<bits/stdc++.h>
using namespace std;

int lengthOfLastWord(string s) 
{
        int count=0;
        bool check=false;
        for(int i=s.size()-1;i>=0;i--)
        {
            if(s[i]!=' ')
            {
                count++;
                check=true;
            }
            if(s[i]==' ' && check)
                break;
        }
        return count;
}

    
int main()
{
    string s;
    getline(cin,s);
    cout<<lengthOfLastWord(s);
    return 0;
}
