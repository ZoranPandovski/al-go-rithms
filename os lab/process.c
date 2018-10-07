#include <stdio.h>
#include <stdlib.h>

int main()
{
int n,i,m,j;
printf("Enter the number of processs\n");
scanf("%d",&n);
int b[n],a[n],wt[n],tat[n],rt[n],ct[n],avg_wt=0,avg_tat=0,avg_rt=0,avg_ct=0,tot_bur_time[n+1];
tot_bur_time[0]=0;

for(i=0;i<n;i++)
{
printf("Enter the burst time of the process %d\n",(i+1));
scanf("%d",&b[i]);
printf("Enter the arrival time of the process %d\n",(i+1));
scanf("%d",&a[i]);
}
printf("enter time quantum ");
scanf("%d",&m);
for(i=1;i<=n;i++)
{ 
tot_bur_time[i]=tot_bur_time[i-1]+b[i-1];
}

 for(i=0;i<n;i++)
{
wt[i]=tot_bur_time[i]-a[i];
tat[i]=tot_bur_time[i+1]-a[i];
rt[i]=tot_bur_time[i];
ct[i]=tot_bur_time[i+1];
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

printf("Process Name\tBurst Time\tArrival Time\tW.T\tT.A.T\tR.T\tC.T\n");
for(i=0;i<n;i++)
{
  printf("P%d\t\t%d\t\t%d\t\t%d\t%d\t%d\t%d\n",(i+1),b[i],a[i],wt[i],tat[i],rt[i],ct[i]);
}

printf("Average W.T %d\n",avg_wt);
printf("Average T.A.T %d\n",avg_tat);


printf("GANTT CHART\n");
for(i=0;i<n;i++)
{
  printf("   |P%d|\t",(i+1));
}
printf("\n");
printf(" %d",tot_bur_time[0]);
for(i=1;i<=n;i++)
{
  printf("\t%d",tot_bur_time[i]);
}

printf("\n");

return(0);
}























