#include <bits/stdc++.h>

using namespace std;

int main()
{
    int sum = 0;
    int max_sum = array[0];
    for (int i = 0; i < length; ++i)
    {
        sum += array[i];
        sum = max(0, sum);
        max_sum = max(sum, max_sum);
    }
    return max_sum;
}
