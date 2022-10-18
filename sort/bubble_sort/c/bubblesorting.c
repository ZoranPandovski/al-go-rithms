#include<stdio.h>
void BubbleSort(int n, int a[]){
    int temp,count=0;
    for (int i = 0; i < n-1; i++)
    {
        for (int j = 0; j < n-i-1; j++)
        {
            if(a[j]>a[j+1]){
                temp=a[j];
                a[j]=a[j+1];
                a[j+1]=temp;
                count++;
        }
    }
    if(count==0){
        break;
    }
    }
         printf("The sorted array is:\n");
        for (int k = 0; k <n ; k++)
        {
            printf("%d ",a[k]);
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
    BubbleSort(n,a);
    
return 0;
}
