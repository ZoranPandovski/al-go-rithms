#include<iostream>
#include<vector>
using namespace std;
int main()
{
  int n;
  cout<<"Enter total number of processes\n"; cin>>n;
  vector<int> burstTime(n);    // Array of burst times of processes

  cout<<"Enter burst times for processes.\n";
  for(int i = 0;i < n;i++) {
    cout<<"P["<<i + 1<<"]:";
    cin>>burstTime[i];
  }

  vector<int> waitingTime(n);  // Array of waiting Times of processes
  //calculating waiting time
  for(int i = 1; i < n; i++) {
    waitingTime[i] = 0;
    for(int j = 0; j < i; j++)
      waitingTime[i] += burstTime[j];  // WaitingTime[process] += burstTime[process]
  }

  cout<<"\nProcess\t\tBurst Time\tWaiting Time\tTurnaround Time";
  vector<int> turnAroundTime(n);   // Turn Around time[process] = waitingTime[process] + burstTime[process]
  //calculating turnaround time
  int averageWaitingTime = 0, averageTurnAroundTime = 0;

  for(int i = 0; i < n; i++) {
    turnAroundTime[i] = burstTime[i] + waitingTime[i];
    averageWaitingTime += waitingTime[i];
    averageTurnAroundTime += turnAroundTime[i];
    cout<<"\nP["<<i + 1<<"]"<<"\t\t"<<burstTime[i]<<"\t\t"<<waitingTime[i]<<"\t\t"<<turnAroundTime[i];
  }

  averageWaitingTime /= n;   // Average waiting time = total waiting time / total processes
  averageTurnAroundTime /= n;  // Average turn around time = total turn around time / total processes
  cout<<"\nAverage Waiting Time:"<<averageWaitingTime<<"\n";
  cout<<"Average Turnaround Time:"<<averageTurnAroundTime<<"\n";;
  return 0;
}
