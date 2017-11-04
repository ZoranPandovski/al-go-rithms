#include <stdio.h>

#define MAX_SIZE 50

void swap(int* x,int* y)
{
    int tmp;
    tmp = *x;
    *x = *y;
    *y = tmp;
    return;
}

void bubbleSort(int arr[], int n)
{
    int i, j;

    for(i=0; i<(n-1); i++)
        for(j=n-1; j>i; j--)
            if(arr[j-1] > arr[j])
                swap(&arr[j-1],&arr[j]);
    
}

int main()
{
    int arr[MAX_SIZE];

    int i,n;

    scanf("%d", &n);

    for(i=0;i<n;i++)
        scanf("%d",&arr[i]);

    bubbleSort(arr, n);

    for(i=0;i<n;i++)
        printf("%d ",arr[i]);

    return 0;

}
