# LeetCode 349. Intersection of Two Arrays

# Given two integer arrays nums1 and nums2, return an array of their intersection. 
# Each element in the result must be unique and you may return the result in any order.

# During an interview, one can mention brute force solution which is literally checking every element in arr1 to be present in arr2, and add it to answer array if it does not contain that element already.

# Here is an optimized O(n) solution.
# Explanation: 

# Turning list into a set allows to get rid of all duplicates.
# Example: 
# nums1 = [9,4,9,8,4]
# print( set(nums1) ) # Output: {8, 9, 4}

# Python sets have built-in intersection method which returns a set of unique elements that are present in both sets.
# Example:
# nums1 = [9,4,9,8,4]
# nums2 = [3,9,3,1]
# print( set(nums1).intersection(set(nums2)) ) # Output: {9}

# This gives us an answer to the problem.


def arraysIntersection(nums1, nums2):
        return set(nums1).intersection(set(nums2))


# Test 1:

nums1 = [9,4,9,8,4]
nums2 = [3,9,3,1]

print(arraysIntersection(nums1, nums2)) # {9}

# Test 2:

nums1 = [4,9,5]
nums2 = [9,4,9,8,4]

print(arraysIntersection(nums1, nums2)) # {9, 4}

# Test 3:

nums1 = [1,2,2,1]
nums2 = [2,2]

print(arraysIntersection(nums1, nums2)) # {2}
