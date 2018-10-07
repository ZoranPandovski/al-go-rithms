#include<stdio.h>


int main()
{int n,at[10],bt[10],ct[10],p_no[10],count=0,z=1,cct[10];
ct[0]=1;
p_no[0]=1;
int tbt=0;
printf("Enter the number of process");
scanf("%d",&n);
printf("Enter the arrival time");
for(int i=0;i<n;i++)
scanf("%d",&at[i]);
printf("Enter the burst time");
for(int i=0;i<n;i++)
scanf("%d",&bt[i]);

printf("arrival time\n");
for(int i=0;i<n;i++)
printf("%d\n",at[i]);
printf("burst time\n");
for(int i=0;i<n;i++)
printf("%d\n",bt[i]);

for(int i=0;i<n;i++)
tbt=tbt+bt[i];
printf("%d\n",tbt);


bt[9]=999;
for(int j=0;count!=n;j++)
{int smallest=9;
for(int i=0;i<n;i++)
{if(at[i]<=j && bt[i]<bt[smallest] && bt[i]>0)
smallest=i;
}
bt[smallest]--;
if(bt[smallest]==0)
{ct[z]=j+1;
p_no[z]=smallest+1;
z++;
count++;
}
}


int i=0;
for(int j=0;j<n;j++)
{
while((p_no[j]!=p_no[i+1])&&(ct[i]!=tbt))
i++;
if(p_no[j]==p_no[i+1])
{cct[j]=ct[i+1];
}
else 
cct[j]=ct[j+1];
}
for(int i=0;i<n;i++)
printf("%d\n",cct[i]);


for(int i=0;i<z;i++)
printf("|P%d|\t",p_no[i]);
printf("\n");
for(int i=0;i<z;i++)
printf("%d\t",ct[i]);

return 0;
}
