#include <stdio.h>
#include<stdlib.h>


int main()
{  int i,n,min=156,pos=66,d,j,q;
  printf("Enter the number of processes\n");
  scanf("%d",&n);
  int arr[n],bt[n],at[n],ct[n],tat[n],wt[n],rt[n],diff[n-1],tot_bur_time[n+1],p[n],avg_wt=0,avg_tat=0,avg_rt=0,avg_ct=0;
  for(i=0;i<n;i++)
  {
    printf("Enter the burst time of the process %d\n",(i+1));
    scanf("%d",&bt[i]);
    printf("Enter the arrival time of the process %d\n",(i+1));
    scanf("%d",&at[i]);
   }
    ct[0]=bt[0];
    tot_bur_time[0]=0;
    tot_bur_time[1]=bt[0];
    p[0]=1;
  

   for(i=0;i<n-1;i++)
{
    diff[i]=bt[i+1]-at[i+1];
   }
  q=n-1;
 
 
  for(j=1;j<n;j++)
{
   for(i=0;i<n-1;i++)
  {
      if(diff[i]<min)
    {  
      min=diff[i];
      pos=i;
}
   }
   diff[pos]=156;min=156;
   p[j]=pos+2;
} 

   for(i=2;i<=n;i++)
{ d=p[i-1];
tot_bur_time[i]=tot_bur_time[i-1]+bt[d-1];
 
}





   for(i=1;i<n;i++)
{ d=p[i];

 ct[d-1]=tot_bur_time[i+1];
}

  printf("\n");
  printf("GANTT CHART\n");
for(i=0;i<n;i++)
{
  printf("   |P%d|\t",p[i]);
}
printf("\n");
printf(" %d",tot_bur_time[0]);
for(i=1;i<=n;i++)
{
  printf("\t%d",tot_bur_time[i]);
}
printf("\n");


for(i=0;i<n;i++)
{
tat[i]=ct[i]-at[i];
wt[i]=tat[i]-bt[i];
}


  rt[0]=0;
   for(i=1;i<n;i++)
{ d=p[i];

 rt[d-1]=tot_bur_time[i];
}
printf("Process Name\tBurst Time\tArrival Time\tC.T\tT.A.T\tW.T\tR.T\n");
for(i=0;i<n;i++)
{
  printf("P%d\t\t%d\t\t%d\t\t%d\t%d\t%d\t%d\n",(i+1),bt[i],at[i],ct[i],tat[i],wt[i],rt[i]);
}


for(i=0;i<n;i++)
{
avg_wt=avg_wt+wt[i];
avg_tat=avg_tat+tat[i];
avg_rt=avg_rt+rt[i];
avg_ct=avg_rt+ct[i];
}
avg_wt=avg_wt/n;
avg_tat=avg_tat/n;
avg_rt=avg_rt/n;
avg_ct=avg_ct/n;

printf("Average W.T %d\n",avg_wt);
printf("Average T.A.T %d\n",avg_tat);
printf("Average R.T %d\n",avg_rt);
printf("Average C.T %d\n",avg_ct);

return 0;
}


























































