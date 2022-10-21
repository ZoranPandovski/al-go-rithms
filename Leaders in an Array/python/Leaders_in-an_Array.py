# function for finding leaders
def leaderprint(arr, n):
 
    for i in range(0, n):
        for j in range(i, n):
            if (arr[i] < arr[j]):
                break
            if (j == n - 1):
                print(arr[i]," is a leader")
 
arr = [ 7, 6, 4, 5, 0, 1 ]
n = len(arr)
# calling function
leaderprint(arr, n)
