#### Rat in a maze
Given a MxN maze as binary matrix where each block is either 0 or 1, where 0 means wall and 1 means entry. A rat starts from source (upper leftmost block i.e maze[0][0]) and has to reach destination (lower rightmost block i.e. maze[M][N]). The rat can move only in two directions, forward and down. 

One simple algorithm to solve this backtracking problem is to generate all paths from source to destination and one by one check if the generated path satisfies the constraints.
