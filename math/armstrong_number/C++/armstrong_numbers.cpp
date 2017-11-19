#include<iostream>
#include<stdio.h>

using namespace std;
int armstrong(int N1,int N2)
{
    int x,r,n,s,start,last;
    //cout<<"enter the two no.s between which u want armstrong no.s ";
    start=N1;
    last=N2;
    for(n=start;n<=last;n++)
    {
        x=n;
        s=0;
        while(x!=0)
            {
                r=x%10;
                s=s+r*r*r;
                x=x/10;
            }
        if(s==n)
            {
                cout<<n;
            }

    }

}
int main()
{
    int N1,N2;
    cin>>N1>>N2;
    armstrong(N1,N2);
}



