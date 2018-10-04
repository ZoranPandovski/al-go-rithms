#include <iostream>

unsigned int catalan(unsigned int n)
{
    if (n <= 1)
    {
        return 1;
    }
 
    unsigned int res{ 0 };
    for (unsigned int i{ 0 }; i < n; ++i)
    {
        res += catalan(i) * catalan(n - i - 1);
    }
    return res;
}

int main()
{
    for (unsigned int i{ 0 }; i < 10; ++i)
    {
        std::cout << catalan(i) << std::endl;
    }
}