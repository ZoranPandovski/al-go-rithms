#include<stdio.h>
void insertionSort(int a[],int n){
    int temp,j,i;
    for (i = 1; i < n; i++)
    {
        temp=a[i];
        j=i-1;
        while (j>=0 && a[j]>temp)
        {
            a[j+1]=a[j];
            a[j]=temp;
            j--;
        }
    }
    for (int i = 0; i < n; i++)
    {
        printf("%d ",a[i]);
    }
    
    
}
int main(){
     int a[99],n;
    printf("Enter the size of the array:\n");
    scanf("%d",&n);
    printf("Enter the elements of the array:\n");
    for (int i = 0; i < n; i++)
    {
        scanf("%d",&a[i]);
    }
    insertionSort(a,n);
return 0;
}
