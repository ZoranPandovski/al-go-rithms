#include<stdio.h>
void bubble_sort(int arr[],int n)
{
    int i,j,temp;
    for(i=0;i<n-1;i++)
    {
        for(j=0;j<n-1-i;j++)
        {
            if(arr[j]>arr[j+1])
            {
                temp=arr[j];
                arr[j]=arr[j+1];
                arr[j+1]=temp;
            }
        }
    }
}
int main()
{
    int arr[100],n;
    printf("Enter the size of the array: \n");
    scanf("%d",&n);
    printf("Enter %d numbers \n", n);
    for(int i=0;i<n;i++)
    {
        scanf("%d",&arr[i]);
    }
    bubble_sort(arr,n);
    for (int i = 0; i < n; i++)
    {
        printf("%d\t",arr[i]);
    }

}
