### Knapsack Problem (0-1 Knapsack)

The knapsack problem or rucksack problem is a problem in combinatorial optimization: Given a set of items, 
each with a weight and a value, determine the number of each item to include in a collection so that the total weight 
is less than or equal to a given limit and the total value is as large as possible. It derives its name from the problem 
faced by someone who is constrained by a fixed-size knapsack and must fill it with the most valuable items.

![](https://github.com/arijitkar98/al-go-rithms/blob/master/dp/knapsack_problem/Knapsack_Wiki.png)

The 0-1 Knapsack Problem is when the knapsack can only be filled using the objects as whole pieces and not
by filling the knapsack using objects partially. This problem can be easily be solved using Dynamic Programming 
paradigm.

#### Working of the algorithm

The idea is to use recursion to solve this problem. For each item, there are two possibilities 

(1) We include current item in knapSack and recurse for remaining items with decreased capacity of Knapsack. If the capacity 
    becomes negative, do not recuse or return -INFINITY.

(2) We exclude current item from knapSack and recurse for remaining items.

Finally, we return maximum value we get by including or excluding current item. The base case of the recursion would 
be when no items are left or capacity becomes 0.

We use a table to store the answers to the subproblems and finally return the value of the last element of the table.