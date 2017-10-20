Knapsack Problem

Problem Scenario:
A thief is robbing a store and can carry a maximal weight of W into his knapsack. There are n items available in the store and weight of ith item is wi and its profit is pi. What items should the thief take?

In this context, the items should be selected in such a way that the thief will carry those items for which he will gain maximum profit. Hence, the objective of the thief is to maximize the profit.

Algorithm:
Assume knapsack holds weight W and items have value vi and weight wi
Rank items by value/weight ratio: vi / wi
Thus: vi / wi ≥ vj / wj, for all i ≤ j
Consider items in order of decreasing ratio
Take as much of each item as possible