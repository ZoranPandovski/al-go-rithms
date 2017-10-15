### Problem
A list of N activities is given ( each having its own start time (Si) and finish time (Fi) ). Two activities with start times Si, Sj and 
finish times Fi, Fj respectively are said to be non conflicting if Si > Fj or Sj > Fi. Find the maximum number of activities which we can 
schedule so that there are no conflicting activities among those scheduled.

### Solution
The greedy choice is to always pick the next activity whose finish time is least among the remaining activities and the start time is more than or equal to the finish time of previously selected activity. We can sort the activities according to their finishing time so that we always consider the next activity as minimum finishing time activity.

1) Sort the activities according to their finishing time
2) Select the first activity from the sorted array and print it.
3) For remaining activities in the sorted array.
       --If the start time of this activity is greater than or equal to the finish time of previously selected activity then select this activity and print it.
