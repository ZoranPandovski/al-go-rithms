def find_leaders(arr):
    n = len(arr)
    leaders = [arr[n-1]]

    # Traverse the array from right to left
    max_so_far = arr[n-1]
    for i in range(n-2, -1, -1):
        if arr[i] >= max_so_far:
            leaders.append(arr[i])
            max_so_far = arr[i]

    return leaders[::-1] # reverse the order to get the leaders in left to right order

# Example usage
arr = [16, 17, 4, 3, 5, 2]
leaders = find_leaders(arr)
print(leaders) # Output: [17, 5, 2]
