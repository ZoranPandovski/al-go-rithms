#include <iostream>
using namespace std;

unsigned int Factorial(unsigned int n);
int main()
{
    unsigned int n;
    cout<<"\n\n\t\tFACTORIAL";
    cout<<"\n\n\tEnter a number : ";
    cin>>n;
    cout<<"\n\tFactorial of "<<n<<" is "<<Factorial(n);
    return 0;
}

unsigned int Factorial(unsigned int n){
    if(n==0)
        return 1;
    return n*Factorial(n-1);
}