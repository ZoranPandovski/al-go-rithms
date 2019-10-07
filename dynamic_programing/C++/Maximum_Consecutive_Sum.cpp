#include <bits/stdc++.h>

using namespace std;

int main()
{
	int array[7] = {7, 6, -5, -8, 6, -2, 10};		// Maximum consecutive sum would be 6 + (-2) + 10 = 14
    int sum = 0;
    int max_sum = array[0];
    for (int i = 0; i < (sizeof(array)/sizeof(int)); ++i)
    {
        sum += array[i];
        sum = max(0, sum);
        max_sum = max(sum, max_sum);
    }
    cout << max_sum;
	return 0;
}
