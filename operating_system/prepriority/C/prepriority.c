#include <stdio.h>
#include <stdlib.h>

int main()
{
int n,i,j,lastarrival,q;
printf("*****HIGHER NUMBER DENOTES HIGHER PRIORITY*****\n");
printf("Enter the number of processs\n");
scanf("%d",&n);
int b[n],a[n],wt[n],tat[n],rt[n],ct[n],avg_wt=0,avg_tat=0,avg_rt=0,avg_ct=0,tot_bur_time[n+1],p[n],gantt1[100],gantt2[100],priority=-56,process[100],pos,k,b_copy[n];
tot_bur_time[0]=0;

for(i=0;i<100;i++)
{
   gantt1[i]=0;
   gantt2[i]=0;
}


for(i=0;i<n;i++)
{
printf("Enter the burst time of the process %d\n",(i+1));
scanf("%d",&b[i]);
printf("Enter the arrival time of the process %d\n",(i+1));
scanf("%d",&a[i]);
printf("Enter the priority of the process %d\n",(i+1));
scanf("%d",&p[i]);
process[i]=i+1;
b_copy[i]=b[i];
}



for(i=0;i<n;i++)
{
  
 

  for(j=0;j<=i;j++)
{  
   if(p[j]>priority && b[j]!=0)
  {
    priority=p[j];
    pos=j;
    
  }
}
 if(b[pos]>0)
{
if(b_copy[pos]==b[pos])
rt[pos]=i;

gantt2[i]=i;
gantt1[i]=process[pos];
b[pos]=b[pos]-1;
if(b[pos]==0)
ct[pos]=i;
}
}

q=i;
 
for(k=0;k<n;k++)
{

  for(j=0;j<n;j++)
{  
   if(p[j]>priority && b[j]>0)
  {
    priority=p[j];
    pos=j;
    
  }
}
 if(b[pos]>0)
{
if(b_copy[pos]==b[pos])
rt[pos]=i;

gantt2[q]=i;
gantt1[q]=process[pos];
i=i+b[pos];
q++;
b[pos]=0;
p[pos]=-56;
priority=-56;
if(b[pos]==0)
ct[pos]=i;
}
}
gantt2[q]=i;

for(i=0;i<n;i++)
{
rt[i]=rt[i]-a[i];
tat[i]=ct[i]-a[i];
wt[i]=tat[i]-b_copy[i];
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







printf("*****GANTT CHART*****\n");
for(i=0;i<100;i++)
{
  if(gantt1[i]!=0)
  printf(" P%d\t",gantt1[i]);
}
printf("\n");
printf(" %d ",gantt2[0]);
for(i=0;i<100;i++)
{
  if(gantt2[i]!=0)
  printf("%d\t",gantt2[i]);
}

printf("\n");




printf("Process Name\tBurst Time\tArrival Time\tW.T\tT.A.T\tR.T\tC.T\n");
for(i=0;i<n;i++)
{
  printf("P%d\t\t%d\t\t%d\t\t%d\t%d\t%d\t%d\n",(i+1),b_copy[i],a[i],wt[i],tat[i],rt[i],ct[i]);
}

printf("Average W.T %d\n",avg_wt);
printf("Average T.A.T %d\n",avg_tat);
printf("Average R.T %d\n",avg_rt);
printf("Average C.T %d\n",avg_ct);




return 0;

}





















 
