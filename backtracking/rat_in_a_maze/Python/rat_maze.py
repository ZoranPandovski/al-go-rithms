from __future__ import print_function
#this program solves any mxn rat maze with the given conditions using recursion
import os

def printgrid(grid,m,n):  #to print the grid

    print("\n")
    for i in grid:
        for j in i:
            if j==0:
                print("#", end=' ')   #to print the wall
            elif j==1:
                print(".", end=' ')   #to print the entry
            else :
                print("~", end=' ')   #to print the rat's path

        print('') 

    print("\n")       


def solve(grid, ratPostion,m,n): #this function solves one step of the maze each time it is called
    
    fail=0                 #this variable takes value 1 if the rat reaches a dead end

    

    if grid[ratPosition[0]][ratPosition[1]]==2 :      #if the rat reaches the exit of the maze
        return -1
        
    else:

        grid[ratPosition[0]][ratPosition[1]]=3       #marks the path of the rat in the grid
        
        if ratPosition[1]!=n-1 and grid[ratPosition[0]][ratPosition[1]+1] in [1,2]:   #checks if it is possible to move down
            ratPosition[1]+=1        #rat moves one step forward
            fail=solve(grid,ratPosition,m,n)  #to solve the next step
            

        if fail==-1:   #if the rat has reached the end. Control must go back to the main scope
            return -1

        if ratPosition[0]!=m-1 and grid[ratPosition[0]+1][ratPosition[1]] in [1,2]:  #checks if it is possible to move forward
            ratPosition[0]+=1     #rat moves one step downward
            fail=solve(grid, ratPosition,m,n)   #to solve the next step
            


        if fail==-1:             #if the rat has reached the end. Control must go back to the main scope
            return -1   

        if fail!=-1:    #this condition is satisfied if the rat reaches a dead end in both possible movements
            
            
            grid[ratPosition[0]][ratPosition[1]]=1     #unmarks the current spot
            
            if grid[ratPosition[0]][ratPosition[1]-1]==3:   #this if else is to move back to the previous step
                ratPosition[1]-=1

            else:
                ratPosition[0]-=1     

            return 1       #returns 1 to the fail variable of the previous step

        
            



os.system("clear")
grid=[]

m=input("enter the value of m(width of grid): ")
n=input("enter the value of n(height of the grid): ")

print("Enter the elements of the grid(0:wall, 1:entry)")

for i in range(m):
    temp=[]
    for j in range(n):
        temp.append(input())   #enters one row of the grid
    grid.append(temp)         #enters a row into the grid

grid[m-1][n-1]=2  #to represent the end
ratPosition=[0,0]  #to represent the rat's position

solve(grid, ratPosition,m,n)

printgrid(grid,m,n)