/* =========================================================================
 * First Come First Serve Scheduling
 *
 * DESCRIPTION
 * ===========
 * This is a simple C program to simulate the first come first serve
 * scheduling. The purpose of this program is to calculate the waiting time,
 * average waiting time and turn around time for a user input process queue.
 *
 * =========================================================================
 */

#include <stdio.h>

void fcfs(int );				/* to implement first come first serve scheduling */
void turn_around(int, int [], int []);		/* to calculate turn around time */

int main()
{
	static int size;			/* size of the queue */

	printf("Enter the total number of processes: ");
	scanf("%d", &size);

	if(size == 0)	goto empty_queue;	/* no process in the queue */
	fcfs(size);				/* first come first serve */

	return 0;				/* end of run */

	empty_queue:	printf("\nProcess queue is empty. End of run.\n");
}

/* fcfs : to implement first come first serve scheduling */
void fcfs(int size)
{
	int i, j;float result=0.0;
	int arrival[size], burst[size], waiting[size];

	for(i=0; i<size; ++i)	waiting[i]=0;	/* initialize all values with 0 */

	/* input the arrival time and burst time for each process */
	for(i=0; i<size; ++i) {
		printf("\nEnter arrival time for process %d : ", i+1);
		scanf("%d", &arrival[i]);

		printf("Enter burst time for process %d : ", i+1);
		scanf("%d", &burst[i]);
	}

	/* first come first serve */
	for(i=1; i<size; ++i) {
		result=0.0;
		for(j=0; j<i; ++j)	result+= burst[j];
		waiting[i]=result - arrival[i];	/* waiting time = starting time - arrival time */
	}

	/* print the waiting time */
	printf("\nWaiting Time:\t");
	for(i=0; i<size; ++i)
		printf("%d\t", waiting[i]);

	result=0.0;
	/* average waiting time */
	for(i=0; i<size; ++i)	result+=waiting[i];

	result=result/size;

	printf("\nAverage Waiting Time:\t%f", result);

	/* turn around time */
	turn_around(size, burst, waiting);

	printf("\n");
}

/* turn_around : to calculate turn around time for each process */
void turn_around(int size, int burst[], int waiting[])
{
	int i;
	int turn_around_time[size];

	for(i=0; i<size; ++i)
		turn_around_time[i]= burst[i] + waiting[i];	/* turn around time = burst time + waiting time */

	printf("\nTurn Around Time:\t");
	for(i=0; i<size; ++i)
		printf("%d\t", turn_around_time[i]);
}
