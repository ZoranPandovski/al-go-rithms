def printAns(grid):
    for i in range(9):
        for j in range(9):
            print(grid[i][j], end=' ')
        print()

def isValid(grid, r, c, num):
    
    for i in range(9):
        
        if grid[r][i]==num:
            return False
    for j in range(9):
        if grid[j][c]==num:
            return False
    
    r=r-r%3
    c=c-c%3
    for i in range(3):
        for j in range(3):
            if grid[r+i][j+c]==num:
                return False
                
    return True


   
def sudokuSolver(grid, r, c):
    if r==8 and c==9:
        return 1
    
    if c==9:
        c=0
        r=r+1

    if grid[r][c]>0:
        return sudokuSolver(grid, r, c+1)
        
    for num in range(1,10,1):
        if isValid(grid, r, c, num):
            grid[r][c]=num
            if sudokuSolver(grid,r,c+1):
                return True
        grid[r][c]=0
        
    return False
        







grid = [[3, 0, 6, 5, 0, 8, 4, 0, 0],
        [5, 2, 0, 0, 0, 0, 0, 0, 0],
        [0, 8, 7, 0, 0, 0, 0, 3, 1],
        [0, 0, 3, 0, 1, 0, 0, 8, 0],
        [9, 0, 0, 8, 6, 3, 0, 0, 5],
        [0, 5, 0, 0, 9, 0, 6, 0, 0],
        [1, 3, 0, 0, 0, 0, 2, 5, 0],
        [0, 0, 0, 0, 0, 0, 0, 7, 4],
        [0, 0, 5, 2, 0, 6, 3, 0, 0]]
        
if sudokuSolver(grid, 0, 0):
    printAns(grid)
else:
    print("No Solution Exits")
