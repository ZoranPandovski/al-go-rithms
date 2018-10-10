#include <stdio.h>
#include <stdlib.h>

int main()
{
int n,i,m,j,k=0;
printf("Enter the number of processs\n");
scanf("%d",&n);
int b[n],a[n],wt[n],tat[n],rt[n],ct[n],tot_bur_time=0,waiting[n],highest=-1,pos,b_copy[n],gantt[100],process[100];
float hrrn[n],avg_wt=0.0,avg_tat=0.0,avg_rt=0.0,avg_ct=0.0;
	
for(i=0;i<100;i++)
{
  gantt[i]=0;
  process[i]=0;
}


for(i=0;i<n;i++)
{
printf("Enter the burst time of the process %d\n",(i+1));
scanf("%d",&b[i]);
printf("Enter the arrival time of the process %d\n",(i+1));
scanf("%d",&a[i]);
b_copy[i]=b[i];
}

for(i=0;i<n;i++)
{ 
tot_bur_time=tot_bur_time+b[i];
}

for(i=0;i<tot_bur_time;)
{
  for(j=0;j<n;j++)
    {
       waiting[j]=i-a[j];
       if (waiting[j]<0 || b[j]==0)
              {
                    hrrn[j]=-2.0;
               }
        else
               {
                    hrrn[j]=(float)((float)(waiting[j]+b[j])/(float)b[j]);
          
               }
    }

   for(j=0;j<n;j++)
   {   
      if (hrrn[j]>highest && b[j]!=0 && hrrn[j]>0.0)
        {
           highest=hrrn[j];
           pos=j;
         }
                 
    }
   
    process[k]=pos+1;
    gantt[k+1]= gantt[k]+b[pos];
     rt[pos]=i-a[pos];
     i=i+b[pos];
     ct[pos]=i;
     k++;
     b[pos]=0;
     highest=-1;

}

printf("\n\n");


printf("       *****GANTT CHART*****\n");
printf("\n\n");
for(i=0;i<100;i++)
{  
  if(process[i]!=0)
  printf("   |P%d|\t",process[i]);
}
printf("\n");


for(i=0;i<100;i++)
{  
  if(gantt[i]!=0 || i==0)
  printf("%d\t",gantt[i]);
}

printf("\n");




 for(i=0;i<n;i++)
{

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
avg_wt=avg_wt/(float)n;
avg_tat=avg_tat/(float)n;
avg_rt=avg_rt/(float)n;
avg_ct=avg_ct/(float)n;

printf("\n\n");



printf("Process Name\tBurst Time\tArrival Time\tW.T\tT.A.T\tR.T\tC.T\n");
for(i=0;i<n;i++)
{
  printf("P%d\t\t%d\t\t%d\t\t%d\t%d\t%d\t%d\n",(i+1),b_copy[i],a[i],wt[i],tat[i],rt[i],ct[i]);
}

printf("\n\n");
printf("Average W.T     %f\n",avg_wt);
printf("Average T.A.T   %f\n",avg_tat);
printf("Average R.T     %f\n",avg_rt);
printf("Average C.T     %f\n",avg_ct);



return 0;

}























  
