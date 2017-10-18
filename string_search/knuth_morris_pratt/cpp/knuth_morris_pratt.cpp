#include<bits/stdc++.h>
using namespace std;

int pi[100010],m,n;
string pat,text;

void buildpi()
{
    pi[0]=0;
    for(int i=1;i<m;i++)
    {
        int j=pi[i-1];
        for(;;)
        {
            if(pat[j]==pat[i])
            {
                pi[i]=j+1;
                break;
            }
            else if(j==0)
            {
                pi[i]=0;
                break;
            }
            j=pi[j-1];
        }
    }
}

void matchtext()
{
    int i=0,j=0; // i for text and j for pattern
    while(i<n)
    {
        if(pat[j]==text[i])
        {
            i++;
            j++;
        }
        if(j==m)
        {
            cout<<i-j<<endl;
            j=pi[j-1];
        }
        else 
        {
            while(i<n && pat[j]!=text[i])
            {
                if(j!=0)
                    j=pi[j-1];
                else
                    i++;
            }
        }
    }
}

int main()
{
    cin>>pat>>text;
    n=text.length();
    m=pat.length();
    buildpi();
    matchtext();
    return 0;
}
