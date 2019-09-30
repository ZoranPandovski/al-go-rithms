#include <iostream>

using namespace std;

unsigned factorial(const unsigned num)
{
    if(num <= 1)
    {
        return 1;
    }
    return num*factorial(num-1);
}

bool isStrong(const unsigned num)
{
    if(num == 0) return false;

    unsigned sum = 0;
    for(int i = num; i!=0; i/=10)
    {
        sum += factorial(i%10);
    }
    return sum==num;
}

int main()
{

    cout<<isStrong(145);
    return 0;
}
