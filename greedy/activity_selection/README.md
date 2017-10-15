# Activity Selection Problem

## Problem Statement:

A list of N activities is given ( each having its own start time (Si) and finish time (Fi) ). Two activities with start times Si, Sj and 
finish times Fi, Fj respectively are said to be non conflicting if Si > Fj or Sj > Fi. Find the maximum number of activities which we can 
schedule so that there are no conflicting activities among those scheduled.

## Constraints:
```
1 <= N <= 100000
1 <= Si <= Fi <= 1e9
```
## Input:
First line contains integer N, the number of activities.
Next N lines each contain two integers Si and Fi (start and finish time of activity i)

## Output:
Output one single integer (maximum number of activities which you can schedule)

## Example:
### Input :
```
3
2 3
4 4
1 5
```
### Output:
```
2
```

## Explanation
Let the give set of activities be ```S = {1, 2, 3, ..n}``` and activities be sorted by finish time. The greedy choice is to always pick activity 1. How come the activity 1 always provides one of the optimal solutions. We can prove it by showing that if there is another solution B with first activity other than 1, then there is also a solution A of same size with activity 1 as first activity. Let the first activity selected by B be k, then there always exist ```A = {B – {k}} U {1}```.(Note that the activities in B are independent and k has smallest finishing time among all. Since k is not 1, ```finish(k) >= finish(1))```

