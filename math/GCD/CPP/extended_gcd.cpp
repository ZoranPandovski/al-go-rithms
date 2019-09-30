//C++ program to find co-efficients a,b such that a*x + b*y = gcd(x,y)

#include <iostream>
using namespace std;

//Euclidean algorithm
int extended_gcd(int a, int b, int* x, int* y)
{
    if(a == 0)
    {
        *x = 0;
        *y = 1;
        return b;
    }

    int x1, y1;
    int gcd = extended_gcd(b%a,a,&x1,&y1);
    *x = y1 - (b/a)*x1;
    *y = x1;
    return gcd;
}

int main()
{
    //x and y are input for which co-efficients are to be determined
    int a,b,x,y;
    cin>>x>>y;

    //a is co-efficient for x and b is co-efficient for y
    int gcd = extended_gcd(x,y,&a,&b);
    cout<<a<<" "<<b<<" "<<gcd;
}