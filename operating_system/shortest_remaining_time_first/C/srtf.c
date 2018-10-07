#include <stdio.h>
#include <stdlib.h>

int main()
{   
int n,i,j,lar=-56,temp0,temp1,temp2,lar_at,small,pos,k;
printf("Enter the numbers of processes:\n");
scanf("%d",&n);
int arr[3][n],copy_bt[n],ct[n],tat[n],wt[n];

  for(i=0;i<n;i++)
  {
    printf("Enter the burst time of the process %d\n",(i+1));
    scanf("%d",&arr[1][i]);
    printf("Enter the arrival time of the process %d\n",(i+1));
    scanf("%d",&arr[2][i]);
    arr[0][i]=i+1;
   }

  

lar_at=arr[2][n-1];
 for(i=0;i<n;i++)
  {
     copy_bt[i]=arr[1][i];
     ct[i]=0;
}

for(i=0;i<n;i++)
{     small=999;
  for(j=0;j<i;j++)
{
    if(arr[1][j]<small && arr[1][j]>0)
{
    small=arr[1][j];
pos=j;
}
  
    arr[1][pos]=arr[1][pos]-1;
for(k=0;k<n;k++)
{
if(arr[1][k]>0)
ct[k]=ct[k]+1;
}
    

}
}
small=999;

for(i=0;i<n;i++)
{small=999;
  for(j=0;j<n;j++)
{
   if(arr[1][j]<small && arr[1][j]>0)
{
    small=arr[1][j];
pos=j;
    }
 

arr[1][pos]=0;

for(k=0;k<n;k++)
{
if(arr[1][k]>0)
ct[k]=ct[k]+arr[1][pos];
}
 
}
}

for(i=0;i<n;i++)
printf("%d  ",ct[i]);

return 0;
}

  
  
    
    
    
     
   

























