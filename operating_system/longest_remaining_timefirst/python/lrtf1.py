# creating a structure of 4 processes 
p = [[0, 0, 0, 0, 0, 0, 0] for i in range(4)]
# variable to find the total time  
totaltime = 0
prefinaltotal = 0
  
# finding the largest Arrival Time  
# among all the available process  
# at that time  
def findlargest(at): 
    max = 0
    for i in range(4): 
        if (p[i][1] <= at): 
            if (p[i][2] > p[max][2]) : 
                max = i  
      
    # returning the index of the  
    # process having the largest BT  
    return max
  
# function to find the completion 
# time of each process  
def findCT(totaltime):  
    index = 0
    flag = 0
    i = p[0][1]  
    while (True):  
        index = findlargest(i if i <= 4 else 4)     
        print("Process execute at time ", 
                    totaltime, end = " ") 
        print(" is: P", index + 1,  
                        sep = "", end = " ") 
        p[index][2] -= 1
        totaltime += 1
        i += 1
        if (p[index][2] == 0):  
                p[index][6] = totaltime  
                print("Process P", p[index][0],  
                           sep = "", end = " ") 
                print(" is completed at ",  
                     totaltime, end = " ") 
        print() 
          
        # loop termination condition  
        if (totaltime == prefinaltotal):  
            break
  
# Driver code  
if __name__ =="__main__": 
      
    # initializing the process number  
    for i in range(4):  
        p[i][0] = i + 1
  
    for i in range(4): # taking AT 
        p[i][1] = i + 1
  
    for i in range(4):  
  
        # assigning 2, 4, 6, 8 as Burst Time  
        # to the processes backup for displaying 
        # the output in last calculating total 
        # required time for terminating the function().  
        p[i][2] = 2 * (i + 1)  
        p[i][3] = p[i][2]  
        prefinaltotal += p[i][2]  
  
    # displaying the process before executing  
    print("PNo\tAT\tBT") 
  
    for i in range(4):  
        print(p[i][0], "\t",  
              p[i][1], "\t", p[i][2]) 
    print() 
      
    # soritng process according to Arrival Time  
    p = sorted(p, key = lambda p:p[1])  
  
    # calculating initial time when 
    # execution starts  
    totaltime += p[0][1] 
  
    # calculating to terminate loop  
    prefinaltotal += p[0][1]  
    findCT(totaltime)  
    totalWT = 0
    totalTAT = 0
    for i in range(4): 
          
        # since, TAT = CT - AT  
        p[i][5] = p[i][6]- p[i][1]  
        p[i][4] = p[i][5] - p[i][3]  
  
        # finding total waiting time  
        totalWT += p[i][4]  
  
        # finding total turn around time  
        totalTAT += p[i][5]  
  
    print("\nAfter execution of all processes ... ") 
  
    # after all process executes  
    print("PNo\tAT\tBT\tCT\tTAT\tWT" ) 
  
    for i in range(4):  
        print(p[i][0], "\t", p[i][1], "\t",  
              p[i][3], "\t", end = " ") 
        print(p[i][6], "\t",  
              p[i][5], "\t", p[i][4]) 
    print() 
    print("Total TAT = ", totalTAT) 
    print("Average TAT = ", totalTAT / 4.0) 
    print("Total WT = ", totalWT) 
    print("Average WT = ", totalWT / 4.0)
