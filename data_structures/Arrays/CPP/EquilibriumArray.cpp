#include <bits/stdc++.h>
using namespace std;

int equilibrium(int arr[], int n)
{
    int i, j;
    int leftsum, rightsum;

    for (i = 0; i < n; ++i)
    {

        /* get left sum */
        leftsum = 0;
        for (j = 0; j < i; j++)
            leftsum += arr[j];

        /* get right sum */
        rightsum = 0;
        for (j = i + 1; j < n; j++)
            rightsum += arr[j];

        /* if leftsum and rightsum
        are same, then we are done */
        if (leftsum == rightsum)
            return i;
    }

    return -1;
}

// Driver code
int main()
{
    int arr[] = {-7, 1, 5, 2, -4, 3, 0};
    int arr_size = sizeof(arr) / sizeof(arr[0]);

    // Function call
    cout << equilibrium(arr, arr_size);
    return 0;
}