### Coin Change Problem

We are given a value N and we have infinite supply of each of S = { S1, S2, .. , Sm} valued coins, 
if we want to make change for N cents how many ways can we make the change? The order of coins doesn’t matter.

For example, for N = 5 and S = {1,2,3}, 
there are four solutions: {1,1,1,1,1},{1,1,1,2},{1,2,2},{1,1,3},{2,3}. 
So output should be 5.

To count total number solutions, we can divide all set solutions in two sets:

1) Solutions that do not contain mth coin (or Sm).
2) Solutions that contain at least one Sm.

Let count(S[], m, n) be the function to count the number of solutions, then it can be written as sum of 
count(S[], m-1, n) and count(S[], m, n-Sm).

Therefore, the problem has optimal substructure property as the problem can be solved using solutions to subproblems.

To solve the problem we create a dp table having m+1 rows and n+1 columns and biuld it in a bottom up manner.

For the above example the table looks as follows:

![](https://github.com/arijitkar98/al-go-rithms/blob/master/dp/coin_change/Coin-Change-Problem.jpg)

We return the last element of the table.
