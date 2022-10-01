#include<bits/stdc++.h>
using namespace std;

int value(char r) 
{

    if (r == 'I')
        return 1;
    if (r == 'V')
        return 5;
    if (r == 'X')
        return 10;
    if (r == 'L')
        return 50;
    if (r == 'C')
    return 100;
    if (r == 'D')
        return 500;
    if (r == 'M')
        return 1000;
    return -1;
}
                    

int romanToInt(string s) 
{
        
    int i=0;
    int sum=0;
    for(i=0;i<s.length();i++)
    {
        if(value(s[i])<value(s[i+1])) 
        {
            sum +=value(s[i+1])-value(s[i]);
            i++;
            continue;
        }
        
        sum +=value(s[i]);
        
    }
    return sum;
}

int main()
{
    string str="XXIV";
    cout<<romanToInt(str);

    return 0;
}
