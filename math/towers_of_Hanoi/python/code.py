from __future__ import print_function
# created by vidit varshney
# If you this code help you then please give star and follow to get more 

# Solution Of Tower Of Hanoi Using Recursive Function...
  
def TowerOfHanoi(n , from_rod, to_rod, aux_rod): 
    
    if n == 1: 
        
        print("Move disk 1 from rod",from_rod,"to rod",to_rod) 
        
        return 
    
    TowerOfHanoi(n-1, from_rod, aux_rod, to_rod) 
    
    print("Move disk",n,"from rod",from_rod,"to rod",to_rod) 
    
    TowerOfHanoi(n-1, aux_rod, to_rod, from_rod) 
    
    
# Driver code 

n = input("Enter the number of disks")

TowerOfHanoi(n, 'A', 'C', 'B')  


# A, C, B are the name of rods 
  
