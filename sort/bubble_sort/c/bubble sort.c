#include <stdio.h>

#define N 5

void swap(int* x,int* y)
{
    (*x)=(*x)+(*y);
    (*y)=(*x)-(*y);
    (*x)=(*x)-(*y);
    return;
}
int main()
{
    int arr[N];
    int i,j;
    for(i=0;i<N;i++)
        scanf("%d",&arr[i]);

    for(i=0;i<(N-1);i++){
        for(j=(N-1);j>i;j--){
            if((arr[j-1])>(arr[j])){
                swap(&arr[j-1],&arr[j]);
                /*arr[j-1]=arr[j-1]+arr[j];
                arr[j]=arr[j-1]-arr[j];
                arr[j-1]=arr[j-1]-arr[j];*/

            }
        }
    }
    for(i=0;i<N;i++)
        printf("%d ",arr[i]);

    return 0;
}
