"""Prints a maximum set of activities that can be done by a
single person, one at a time"""
# n --> Total number of activities
# s[]--> An array that contains start time of all activities
# f[] --> An array that conatins finish time of all activities
 
def printMaxActivities(s , f ):
    n = len(f)
    print("The following activities are selected")
 
    # The first activity is always selected
    i = 0
    print(i),
 
    # Consider rest of the activities
    for j in range(n):
        # If this activity has start time greater than
        # or equal to the finish time of previously
        # selected activity, then select it
        if s[j] >= f[i]:
            print(j)
            i = j
# Driver program to test above function
s = list(map(int,input().split()))
f = list(map(int,input().split()))
printMaxActivities(s , f)
