

#include <stdio.h>
#include <stdlib.h>

int main()
{
     int n,i,j=0,quan,tot_bur_time=0,k=0;

    printf("Enter the number of processes\n");
  scanf("%d",&n);
    printf("Enter the time quantum\n");
    scanf("%d",&quan);
  
   int bt[n],at[n],ct[n],tat[n],wt[n],rt[n],process[n],bt_copy[n],avg_rt=0,avg_tat=0,avg_ct=0,avg_wt=0;
  for(i=0;i<n;i++)
  {
    printf("Enter the burst time of the process %d\n",(i+1));
    scanf("%d",&bt[i]);
    printf("Enter the arrival time of the process %d\n",(i+1));
    scanf("%d",&at[i]);
   
   }
   
    for(i=0;i<n;i++)
  { tot_bur_time=tot_bur_time+bt[i];
    process[i]=i+1;
    bt_copy[i]=bt[i];
   }
   // used in gantt chart
   int process_seq[tot_bur_time],i_copy[tot_bur_time];
    for(i=0;i<tot_bur_time;i++)
  {    process_seq[i]=0;
       i_copy[i]=0;
   }   
  
  
      
   
     
     for(i=0;i<tot_bur_time;)
     {  
        
        if(j>4)
        j=0;
        
       if(bt[j]>quan)
       {  i_copy[k]=i;
         if(bt[j]==bt_copy[j])
         rt[j]=i;
         
         bt[j]=bt[j]-quan;
         i=i+quan;
         process_seq[k]=process[j];
         j=j+1;
         
         k=k+1;
        }
        
        else if(bt[j]==quan)
        {i_copy[k]=i;
          if(bt[j]==bt_copy[j])
          rt[j]=i;
          
          
          bt[j]=bt[j]-quan;
          i=i+quan;
          ct[j]=i;
          process_seq[k]=process[j];
          j=j+1;
          
          k=k+1;
         }
         else if(bt[j]==0)
         j=j+1;
         else 
         {  i_copy[k]=i;
           if(bt[j]>0)
           {
            if(bt[j]==bt_copy[j])
            rt[j]=i;
            
            i=i+bt[j];
            bt[j]=0;
            ct[j]=i;
            process_seq[k]=process[j];
            j=j+1;
            
            k=k+1;
           }
          }
          
         }
          
     for(i=0;i<n;i++)
     {
       rt[i]=rt[i]-at[i];
       tat[i]=ct[i]-at[i];
       wt[i]=tat[i]-bt_copy[i];
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
	
	printf("                  GANTT CHART\n");
	  for(i=0;i<tot_bur_time;i++)
  {  if(i>3 && process_seq[i]==0)
      continue;
      else
      printf("   |P%d|\t",process_seq[i]); 
  }  printf("\n");
  
   for(i=0;i<=tot_bur_time;i++)
  {  if(i>3 && i_copy[i]==0)
      continue;
      else
      printf(" %d\t",i_copy[i]);
  }   printf("   %d",tot_bur_time);
	printf("\n\n");
	
	printf("Process Name\tBurst Time\tArrival Time\tW.T\tT.A.T\tR.T\tC.T\n");
	for(i=0;i<n;i++)
	{
	  printf("P%d\t\t%d\t\t%d\t\t%d\t%d\t%d\t%d\n",process[i],bt_copy[i],at[i],wt[i],tat[i],rt[i],ct[i]);
	}
         printf("\n\n");
	printf("Average W.T: %d\n",avg_wt);
	printf("Average T.A.T: %d\n",avg_tat);
	printf("Average R.T: %d\n",avg_rt);
	printf("Average C.T: %d\n",avg_ct);


  
    
      return 0;
      }
            
            
           
           
           
           
           
           
           
           
           
           
           
           
           
           
           
           
           
           
           
           
           
           
           
           
           
           
           
           
           
           
           
           
           
          
          
