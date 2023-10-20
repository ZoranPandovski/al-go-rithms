def equilibrium_point(arr):
    n = len(arr)
    total_sum = sum(arr)
    left_sum = 0
    for i in range(n):
        if left_sum == total_sum - arr[i] - left_sum:
            return i
        left_sum += arr[i]
    return -1
a=int(input("Number of elements in the array:-"))
arr=list(map(int, input("elements of array:-").strip().split()))
equilibrium_index = equilibrium_point(arr)
print(f"Equilibrium index is {equilibrium_index}")