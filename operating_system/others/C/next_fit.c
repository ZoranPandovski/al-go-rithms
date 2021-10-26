#include <stdio.h>
#include <stdlib.h>

void next_fit(int blockSize[],int processSize[],int n,int m){
    int allocation[m];
    int i=0,j=0;
    for (i=0;i<m;i++)
        allocation[i]=-1;
    for (i=0;i<m;i++) {
        while (j<n) {
            if (blockSize[j]>=processSize[i])
             {
                allocation[i]=j;
                blockSize[j]-=processSize[i];
                break;
            }
            j=(j+1)%n;
        }
    }
    printf("\nProcess No.\tProcess Size\tBlock no.\n");
    for (i=0;i<m;i++) {
        printf("%d\t\t",i+1);
        printf("%d\t\t",processSize[i]);
        if (allocation[i]!=-1)
           printf("%d",allocation[i]+1);
        else
           printf("Not Allocated\n");
        printf("\n");
    }
}

int main(){
    int blockSize[]={10,20,300,40,500,60,100};
    int i,n,m;
    n=7;
    printf("Give number of processes:");
    scanf("%d",&m);
    int processSize[m];
    for (i=0;i<m;i++){
        printf("Give process size for process number %d:",i+1);
        scanf("%d",&processSize[i]);
    }
    next_fit(blockSize,processSize,n,m);
    return 0;
 }
