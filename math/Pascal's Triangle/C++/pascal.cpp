//implementation of pascals triangle using factorial in c++.
#include<iostream>
using namespace std;
int factorial(int n)
{
    int i,f=1;
    for(i=1;i<=n;i++)
    {
        f=f*i;
    }
    return f;
}
int main()
{
    int i,j,n;
    cin>>n;
    for(i=0;i<=n;i++)
    {
        for(j=0;j<=i;j++)
        {
            cout<<" ";
            cout<<factorial(i)/(factorial(j)*factorial(i-j))<<" ";
        }
        cout<<endl;
    }
}
