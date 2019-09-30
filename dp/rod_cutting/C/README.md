# Rod Cutting Problem

## Problem Statement:
Given a rod of length n inches and an array of prices that contains prices of all pieces of size smaller than n. Determine the maximum value obtainable by cutting up the rod and selling the pieces.

## Constraints:
```
1 <= N <= 100000
1 <= p[i] <= 10e9
```
## Input:
First line contains integer N, the number of activities.
Next N lines each contain integer arr[i] (value of i length rod)

## Output:
Output one single integer (maximum cost you can gain by cutting)

## Example:
### Input :
```
8
1 5 8 9 10 17 17 20
```
### Output:
```
Maximum Obtainable Value is:22
```

### Explanation:
For example, if length of the rod is 8 and the values of different pieces are given as following, then the maximum obtainable value is 22 (by cutting in two pieces of lengths 2 and 6).
