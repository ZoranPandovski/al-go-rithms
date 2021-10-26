#include <stdio.h>

void bubble_sort(int arr[], int N)
{
    int round, i, temp, flag;
    for (round = 1; round < N - 1; round++)
    {
        flag = 0;
        for (i = 0; i <= N - 1 - round; i++)
        {
            if (arr[i] > arr[i + 1])
            {
                flag = 1;
                temp = arr[i];
                arr[i] = arr[i + 1];
                arr[i + 1] = temp;
            }
        }
        if (flag == 0)
            return;
    }
}

int main()
{
    int arr[] = {9, 11, 24, 36, 58, 49, 35, 28, 65, 8, 69, 55};
    int i;
    int size = sizeof(arr) / sizeof(arr[0]);
    bubble_sort(arr, 12);
    for (i = 0; i <= 11; i++)
        printf(" %d ", arr[i]);
    return 0;
}
