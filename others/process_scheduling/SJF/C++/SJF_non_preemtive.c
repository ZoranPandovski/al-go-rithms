#include<stdio.h>
#include<stdlib.h>

int main(){
  int Arrival_time[100];
  int Burst_time[100];
  int TurnAround_time[100]={0};
  int completion_time[100];
  int waiting_time[100];
  int tSequence[100];
  int count;
  int no_of_process;
  int min;
  int i,j;
  int pointer;
  float total_waiting_time;
  float total_turn_around;
  printf("Enter the no of process \n");
  scanf("%d",&no_of_process);
  printf("Enter Arrival time and Burst time of the Processess\n");
  for(int i=0;i<no_of_process;i++){
    printf("Process - %d  :",i+1);
    scanf("%d%d",&Arrival_time[i],&Burst_time[i]);
  }
  pointer=Arrival_time[0];//intilize the pointer to the first process
  min=0;
  for(int i1=0;i1<no_of_process && Arrival_time[i1]==pointer;i1++){ //find the min burst time process till that arrival time
    if(Burst_time[min]>Burst_time[i1]){
      min=i1; //update the index when we find minimum
    }
  }
  tSequence[min]=1; //minimum Burst_time process shound be first
  completion_time[min]=Arrival_time[min]+Burst_time[min];
  TurnAround_time[min]=completion_time[min]-Arrival_time[min];
  //calculate the completion_time and TurnAround_time for the process which is having min burst time
  waiting_time[min]=0; //waiting time of the min process is zero because thatis executing first
  total_waiting_time=0;
  total_turn_around=TurnAround_time[min];
  count=no_of_process-1; //one process is gone for execution
   j=min;
  //loop till all the processees is executed
  while(count>0){
		for (i=0;i<no_of_process;i++){
			if (TurnAround_time[i]==0){
				min=i;
				while(Arrival_time[i]==Arrival_time[min]){
					if (Burst_time[min]>Burst_time[i] && TurnAround_time[i]==0) {
						min=i;
					}
					i++;
				}
			break;}
		}
		for (i=0;(i<no_of_process && completion_time[j]>= Arrival_time[i]);i++){
			if (Burst_time[min]>Burst_time[i] && TurnAround_time[i]==0)
			{
				min=i;
			}
		}
		tSequence[min]=no_of_process-count+1;
		completion_time[min]=Burst_time[min]+completion_time[j];
		if (Arrival_time[min]>completion_time[j])
			completion_time[min]=Burst_time[min]+Arrival_time[min];
		j=min;
		TurnAround_time[min]=completion_time[min]-Arrival_time[min];
		total_turn_around+=TurnAround_time[min];
		waiting_time[min]=TurnAround_time[min]-Burst_time[min];
		total_waiting_time+=waiting_time[min];
		count-=1;
	}
  printf("******************************************\n");
	printf("SORTEST JOB FIRST SCHEDULING(NON-PREEMPTIVE)\n");
	printf("******************************************\n");
	printf("ProcessNo.\tArrival\t\tBurstTime\tCompletion\tTurnAround\tWaiting\t\tSequence\n");
	for (int i5=0;i5<no_of_process;i5++){
	printf("%d\t\t%d\t\t%d\t\t%d\t\t%d\t\t%d\t\t%d\n",i5+1,Arrival_time[i5],Burst_time[i5],completion_time[i5],TurnAround_time[i5],waiting_time[i5],tSequence[i5]);
	}
	printf("Average Waiting Time: %f\n",total_waiting_time/no_of_process);
	printf("Average TurnAround Time: %f\n",total_turn_around/no_of_process);
  return 0;
}
