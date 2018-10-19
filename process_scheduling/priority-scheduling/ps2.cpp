/*
  Priority scheduling with different arrival time-nonpreemptive

  algorithm approach:https://www.geeksforgeeks.org/operating-system-priority-scheduling-different-arrival-time-set-2/

*/

#include<bits/stdc++.h>

struct process
{
  int pid;
  int bt;
  int at;
  int ct;
  int wt;
  int tat;
  int priority;
};

int main()
{
int i,j,n,total_wt=0,total_tat=0;
float avg_wt,avg_tat;
printf("enter total number of processes\n");
scanf("%d",&n);
struct process proc[n],temp;
printf("enter process-id,arrival-time,burst-time and priority for each process\n");
for(i=0;i<n;i++)
{
    scanf("%d %d %d %d",&proc[i].pid,&proc[i].at,&proc[i].bt,&proc[i].priority);
}

for(i=0;i<n-1;i++)
{
    for(j=i+1;j<n;j++)
    {
        //first sort according to arrival time
        if(proc[i].at>proc[j].at)
        {
          temp=proc[i];
          proc[i]=proc[j];
          proc[j]=temp;
        }
        //if arrival-time is same
        if(proc[i].at==proc[j].at)
        {
            //then sort according to priority
            if(proc[i].priority>proc[j].priority)
            {
               temp=proc[i];
               proc[i]=proc[j];
               proc[j]=temp;
            }
            //if priority is also same
        }
        if(proc[i].at==proc[j].at && proc[i].priority==proc[j].priority)
        {
            if(proc[i].pid>proc[j].pid)
                {
                    temp=proc[i];
                    proc[i]=proc[j];
                    proc[j]=temp;
                }
        }

    }
}
    proc[0].ct=(proc[0].bt+proc[0].at);
    for(i=1;i<n;i++)
    {
        proc[i].ct=proc[i-1].ct+proc[i].bt;
    }
    for(i=0;i<n;i++)
    {
        proc[i].tat=proc[i].ct-proc[i].at;
    }
    for(i=0;i<n;i++)
    {
        proc[i].wt=proc[i].tat-proc[i].bt;
    }

    long int waiting_total=0,turn_around_total=0;

    for(i=0;i<n;i++)
    {
     waiting_total+=proc[i].wt;
     turn_around_total+=proc[i].tat;
    }
    float avg_waiting_time=(float)waiting_total/(float)n;

    float avg_turn_around_time=(float)turn_around_total/(float)n;

    printf("Process\t\tarrival-time\t\tBurst time\t\tpriority\t\twaiting time\t\tTurn_around_time\n");

    for(i=0;i<n;i++)
    {
    printf("%d\t\t\t%d\t\t\t%d\t\t\t%d\t\t\t%d\t\t\t%d\n",proc[i].pid,proc[i].at,proc[i].bt,proc[i].priority,proc[i].wt,proc[i].tat);
    }

    printf("Average waiting time=%f\n",avg_waiting_time);

    printf("Average turn around time=%f\n",avg_turn_around_time);

    return 0;
}
