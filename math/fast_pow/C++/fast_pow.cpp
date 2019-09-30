#include <iostream>

// Fast pow from https://martin.ankerl.com/2007/10/04/optimized-pow-approximation-for-java-and-c-c/
inline double fastPow(const double a, const double b) 
{
    union 
    {
        double d;
        int x[2];
    } u = { a };

    constexpr int shift{ 1072632447 };
    u.x[1] = static_cast<int>(b * (u.x[1] - shift) + shift);
    u.x[0] = 0;
    return u.d;
}

int main()
{
    std::cout << fastPow(16, 0.5) << std::endl;
}