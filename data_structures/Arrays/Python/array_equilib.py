def equilibriumIndex(arr):
    # Please add your code here
    ind = arr.index(sum(arr))
    return ind if ind else -1
    pass

# Main
 n = int(input())
 arr = [int(i) for i in input().strip().split()]
#n=7
#arr = [-7, 1, 5, 2, -4, 3, 0]
print(equilibriumIndex(arr))
