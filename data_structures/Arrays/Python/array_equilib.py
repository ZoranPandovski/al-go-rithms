def equilibriumIndex(arr):
    # Please add your code here
    return arr.index(sum(arr)) or -1

if __name__ == "__main__":
    n = int(input())
    arr = [int(i) for i in input().strip().split()]
    #n=7
    #arr = [-7, 1, 5, 2, -4, 3, 0]
    print(equilibriumIndex(arr))
