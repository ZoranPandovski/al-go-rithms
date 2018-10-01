In the "First come first serve" scheduling algorithm, as the name suggests, the process which arrives first, gets executed first, or we can say that the process which requests the CPU first, gets the CPU allocated first.

First Come First Serve, is just like FIFO(First in First out) Queue data structure, where the data element which is added to the queue first, is the one who leaves the queue first.
This is used in Batch Systems.
It's easy to understand and implement programmatically, using a Queue data structure, where a new process enters through the tail of the queue, and the scheduler selects process from the head of the queue.
A perfect real life example of FCFS scheduling is buying tickets at ticket counter.

Calculating Average Waiting Time

For every scheduling algorithm, Average waiting time is a crucial parameter to judge it's performance.

AWT or Average waiting time is the average of the waiting times of the processes in the queue, waiting for the scheduler to pick them for execution.

Lower the Average Waiting Time, better the scheduling algorithm.
Consider the processes P1, P2, P3, P4 given in the below table, arrives for execution in the same order, with Arrival Time 0, and given Burst Time, let's find the average waiting time using the FCFS scheduling algorithm.

First Come First Serve(FCFS) Scheduling

The average waiting time will be 18.75 ms

For the above given proccesses, first P1 will be provided with the CPU resources,

Hence, waiting time for P1 will be 0
P1 requires 21 ms for completion, hence waiting time for P2 will be 21 ms
Similarly, waiting time for process P3 will be execution time of P1 + execution time for P2, which will be (21 + 3) ms = 24 ms.
For process P4 it will be the sum of execution times of P1, P2 and P3.
The GANTT chart above perfectly represents the waiting time for each process.


