# Problem Statement: Given a Knapsack of a maximum capacity of W and N items each with its own value and weight, 
# throw in items inside the Knapsack such that the final contents has the maximum value.
# 
# Credits to http://www.geeksforgeeks.org/knapsack-problem/ for the best-looking solution.

# Main method
def main():
    # Stores the value of objects
    value = [10, 40, 30, 50]

    # Stores the weight of objects
    weight = [5, 4, 6, 3]

    # Stores the capacity of the knapsack
    W = 10

    # gets total number of objects
    n = len(value)

    print(knapSack(W, weight, value, n))


# A Dynamic Programming based Python Program for 0-1 Knapsack problem
# Returns the maximum value that can be put in a knapsack of capacity W,
# wt array and val array, and n is the total number of objects
def knapSack(W, wt, val, n):
    
    # creates 2D array
    K = [[0 for x in range(W + 1)] for y in range(n + 1)]
 
    # Build table K[][] in bottom up manner
    for i in range(n + 1):
        for w in range(W + 1):
            if i == 0 or w == 0:
                K[i][w] = 0
            elif wt[i - 1] <= w:
                K[i][w] = max(val[i-1] + K[i-1][w-wt[i-1]],  K[i-1][w])
            else:
                K[i][w] = K[i-1][w]
 
    return K[n][W]

main()
 