'''
Function to sort an array in binary buckets (2-radix sort)
'''

def bin_bucket_sort(arr):
    """
    Binary bucket sort / 2-Radix sort
    Time: O(NLog2N)
    Space: O(N)
    
    input: 1D-list array
    output: 1D-list sorted array
    """
    bucket = [[], []]
    aux = list(arr)
    flgkey = 1
    
    while True:
        for ele in aux:
            bucket[int(bool(ele & flgkey))].append(ele)
        if bucket[0] == [] or bucket[1] == []:
            return aux
        aux = list(bucket[0]) + list(bucket[1])
        flgkey <<= 1
        bucket = [[], []]
    

print("Hello To my first program")
l1 = [1, 4, 2, 3, 5, 2, 5, 2]
print(bin_bucket_sort(l1))