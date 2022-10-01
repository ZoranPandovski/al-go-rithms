//Program for Recursive Linear Search

#include<stdio.h>

int rec_lin(int arr[], int low, int high, int key);

int main()
{
    int n, key, result = 0;
    printf("Enter the size of the array\n");
    scanf("%d",&n);
    int array[n];
    printf("Enter the elements of the array\n");
    for(int i=0;i<n;i++)
    {
        scanf("%d",&array[i]);
    }
    printf("Enter the element to be searched\n");
    scanf("%d",&key);
    result = rec_lin(array, 0, n-1, key);
    (result == -1) ? printf("Element %d not found in the array\n", key)
                   : printf("Element %d found in the index %d",key, result);
    return 0;
}

int rec_lin(int arr[], int low, int high, int key)
{
    if(high < low)
        return -1;
    else if(arr[low] == key)
        return low;
    else if(arr[high] == key)
        return high;
    else 
        rec_lin(arr, low+1, high -1, key);
}


