#include <iostream>

using namespace std;

bool isPerfect(const unsigned num)
{
    if(num == 0)
        return false;

    unsigned sum = 0;
    for(int i = 1; i<num; ++i)
    {
        if(num%i==0)
        {
            sum += i;
        }
    }

    return sum==num;
}

int main()
{
    cout<<isPerfect(492);
    return 0;
}
