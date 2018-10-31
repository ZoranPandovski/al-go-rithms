#include <iostream>
#include <vector>

constexpr int getSpan(const int span)
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
    int span = n;

    bool hasSwapped = true;

    while (span > 1)
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
    std::vector<int> a = {8, 4, 1, 56, 3, -44, 23, -6, 78, 0};
    size_t n = a.size();
 
    combSort(a, n);
  
    return 0;
}