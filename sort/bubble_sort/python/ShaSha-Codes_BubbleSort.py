# Bubble Sort runs for n-1 passes
# During each iteration of the innermost loop if number is larger than next number they are both swapped (Ascending).
# During each iteration the Smallest(Descending) or the Largest(Ascending) Numbers get placed to the rightmost part of list,array,tuple etc.
# Here second loop runs n-i-1 because after each pass last element need not be checked again.
# flag is used to check if list is sorted already or not if its sorted redundant passes will not be performed
# Worst Time Complexity:O(n^2)
# Average Time Complexity:O(n^2)
# Best Time Complexity:O(n) List is already sorted need to run the loops only once for checking
# Slow Sorting Algorithm


print("Number Sequence Before Bubble Sort")
seq=[5,2,1,8,3,5,3]
print(seq)

def bubbleSort(nums):
    n=len(nums)
    for i in range(n-1):
        flag=0
        for j in range(n-i-1):
            if(nums[j]>nums[j+1]):
                flag=1
                temp=nums[j]
                nums[j]=nums[j+1]
                nums[j+1]=temp
        if(flag==0):
            break

    return(nums)

print("Number Sequence After Bubble Sort")
print(bubbleSort(seq))

