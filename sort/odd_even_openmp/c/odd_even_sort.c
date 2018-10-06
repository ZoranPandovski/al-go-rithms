/*
 * C Program to Implement Oddeven Sort 
 */
#include <stdio.h>
#define MAX 7
 
void swap(int *,int *);
void oddeven_sort(int *);
 
void main()
{
    int a[MAX], i;
 
    printf("enter the elements in to the matrix :");
    for (i = 0;i < MAX;i++)
    {
        scanf("%d", &a[i]);
    }
    printf("sorted elements are :\n");
    oddeven_sort(a);
    for (i = 0;i < MAX;i++)
    {
        printf(" %d", a[i]);
    }
}
 
/* swaps the elements */
void swap(int * x, int * y)
{
    int temp;
 
    temp = *x;
    *x = *y;
    *y = temp; 
}
 
/* sorts the array using oddeven algorithm */
void oddeven_sort(int * x)
{
    int sort = 0, i;
 
    while (!sort)
    {
        sort = 1;
        for (i = 1;i < MAX;i += 2)
        {
            if (x[i] > x[i+1])
            {
                swap(&x[i], &x[i+1]);
                sort = 0;
            }
        }
        for (i = 0;i < MAX - 1;i += 2)
        {
            if (x[i] > x[i + 1])
            {
                swap(&x[i], &x[i + 1]);
                sort = 0;
            }
        }
    }
}
