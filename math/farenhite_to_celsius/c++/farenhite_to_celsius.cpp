
#include<iostream>
#include<math.h>
using namespace std;
int main()
{
    int i,s,e,w,a;
    cout<<"enter he starting and ending  farenheit value";
    cin>>s>>e;
    cout<<"enter the gap b/w two values";
    cin>>w;
    for(i=s;i<=e;i+=w)
    {
        a=(i-32)/1.8;
        cout<<i<<" "<<a<<endl;
        //s=s+w;
    }
    return(0);
 }
