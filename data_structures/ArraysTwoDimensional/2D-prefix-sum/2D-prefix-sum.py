## 2D prefix sum arrays are used to answer queries about the sum of values in a square area of a 2D array

# Asymptotic complexity: 
# Time: linear (size of the matrix, that is O(N*M), where N and M denote numbers of rows and columns in a matrix) for preprocessing and constant (O(1)) for answering each query.
# Space: We need O(N*M) of additional space for a 2D prefix sum array if we are not allowed to mutate the original array.

# Example problem:
# Forest Queries (https://cses.fi/problemset/task/1652)
# Problem statement:
# Given a n x n grid, where each element is either '*', or '.', answer a number of queries, each of these queries implies counting the number of '*' in a particular square.
initial_grid = ['.*..',
                '*.**', 
                '**..', 
                '****']
# Queries are given in the form of coordinates denoting a square:
# Example queries:
y1, x1, y2, x2 = 2, 2, 3, 4
#y1, x1, y2, x2 = 3, 1, 3, 1
#y1, x1, y2, x2 = 1, 1, 2, 2
#  
# Algorithm is as follows:
# n denotes number of rows == number of columns (as in this case the matrix is square)
n = len(initial_grid)
# First step is to initialize our two-dimensional prefix sum array with zeroes
prefix_sum_grid = [[0]*n for _ in range(n)]
# Then we update prefix_sum_grid values to ones in positions corresponding to coordinates of '*' in the original grid
for i in range(n):
    for j in range(n):
        if initial_grid[i][j] == '*': prefix_sum_grid[i][j] = 1
# Now prefix_sum_grid is exactly initial_grid with zeroes in place of '.', and ones in place of '*'.
# prefix_sum_grid = [
#       [0, 1, 0, 0], 
#       [1, 0, 1, 1], 
#       [1, 1, 0, 0], 
#       [1, 1, 1, 1]
# ]
# Now we calculate prefix sum in both directions (vertically and horizontally) using one-dimentional prefix sum building algorithm:
for i in range(n):
    for j in range(n):
        if i > 0: prefix_sum_grid[i][j] += prefix_sum_grid[i-1][j]
        if j > 0: prefix_sum_grid[i][j] += prefix_sum_grid[i][j-1]
        if i > 0 and j > 0: prefix_sum_grid[i][j] -= prefix_sum_grid[i-1][j-1]
# Each cell in prefix_sum_grid denotes now the number of '*' in a square from position (0,0) to that respective cell (inclusive).
# prefix_sum_grid = [
#       [0, 1, 1, 1], 
#       [1, 2, 3, 4], 
#       [2, 4, 5, 6], 
#       [3, 6, 8, 10]
# ]
# Then we can calculate the sum in any particular square by:
# 1. Taking big square
# 2. Subtracting upper part and left part that is not included in our goal square
# 3. Adding the sum from overlapping area that was subtracted twice in previous step
ans = prefix_sum_grid[y2-1][x2-1]
if y1 > 1: ans -= prefix_sum_grid[y1-2][x2-1]
if x1 > 1: ans -= prefix_sum_grid[y2-1][x1-2] 
if y1 > 1 and x1 > 1: ans += prefix_sum_grid[y1-2][x1-2]
# In this case, our answer is 3, as our goal square contained three '*'.
print(ans) # 3


# Full code including reading from stdin for Forest Queries problem:
# n, q = map(int, input().split())
# grid = [[0]*n for _ in range(n)]
# for i in range(n):
#     row = input()
#     for j in range(n):
#         if row[j] == '*': grid[i][j] = 1
# for i in range(n):
#     for j in range(n):
#         if i > 0: grid[i][j] += grid[i-1][j]
#         if j > 0: grid[i][j] += grid[i][j-1]
#         if i > 0 and j > 0: grid[i][j] -= grid[i-1][j-1]
# for i in range(q):
#     y1, x1, y2, x2 = map(int, input().split())
#     ans = grid[y2-1][x2-1]
#     if y1 > 1: ans -= grid[y1-2][x2-1]
#     if x1 > 1: ans -= grid[y2-1][x1-2] 
#     if y1 > 1 and x1 > 1: ans += grid[y1-2][x1-2]
#     print(ans)

