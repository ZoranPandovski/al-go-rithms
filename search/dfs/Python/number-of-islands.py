class Solution:
    def numIslands(self, grid):
        islands = 0
        for i in range(len(grid)):
            for j in range(len(grid[i])):
                if grid[i][j] == "1":
                    islands += 1
                    self.depthFirstSearch(grid, i, j)
                    
        return islands
                    
    def depthFirstSearch(self, grid, i, j):
        if i < 0 or j < 0 or i >= len(grid) or j >= len(grid[i]) or grid[i][j] != "1":
            return
        
        grid[i][j] = "0"
        self.depthFirstSearch(grid, i, j-1)
        self.depthFirstSearch(grid, i, j+1)
        self.depthFirstSearch(grid, i-1, j)
        self.depthFirstSearch(grid, i+1, j)
                    
        