#include <iostream>
#include <vector>

constexpr unsigned int getSpan(const unsigned int span)
{
    return ((span * 10) / 13 > 1 ? (span * 10) / 13 : 1);
}

template <typename T>
void swap (T &lhs, T &rhs)
{
    const T tmp = lhs;
    lhs = rhs;
    rhs = tmp;
}

void combSort(std::vector<int> &input, int n)
{
    unsigned int span = n;

    bool hasSwapped = true;

    while (span > 1 || hasSwapped)
    {
        span = getSpan(span);
        hasSwapped = false;

        for (unsigned int i = 0; i < n - span; i++)
        {
            if (input[i] > input[i + span])
            {
                swap(input[i], input[i + span]);
                hasSwapped = true;
            }
        }
    }
}

int main()
{
    std::vector<int> a = {15, 4, 1, 9, 3, -8, 23, -6, 563, 0, 5, 7, 10, 65};
    unsigned int n = a.size();
 
    combSort(a, n);
  
    for (int t : a)
    {
        std::cout << t << ' ';
    }
    std::cout << '\n';

    return 0;
}