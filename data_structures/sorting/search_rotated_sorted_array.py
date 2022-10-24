# Search in a Rotated Sorted Array
# You are given a sorted array which is rotated at some random pivot point.
#
# Example: [0,1,2,4,5,6,7] might become [4,5,6,7,0,1,2]
#
# You are given a target value to search. If found in the array return its index, otherwise return -1.
#
# You can assume there are no duplicates in the array and your algorithm's runtime complexity
# must be in the order of O(log n).
#
# Example:
#
# Input: nums = [4,5,6,7,0,1,2], target = 0, Output: 4
#
# Here is some boilerplate code and test cases to start with:

def rotated_array_search(input_list, number):
    """
    Find the index by searching in a rotated sorted array

    Args:
       input_list(array), number(int): Input array to search and the target
    Returns:
       int: Index or -1
    """
    left = 0
    right = len(input_list) - 1

    while left <= right:
        mid = (left + right) // 2
        if number == input_list[mid]:
            return mid

        # left sorted portion
        if input_list[left] <= input_list[mid]:
            if number > input_list[mid] or number < input_list[left]:
                left = mid + 1
            else:
                right = mid - 1

        # right sorted portion
        else:
            if number > input_list[right] or number < input_list[mid]:
                right = mid - 1
            else:
                left = mid + 1
    return -1


def linear_search(input_list, number):
    for index, element in enumerate(input_list):
        if element == number:
            return index
    return -1


def test_function(test_case):
    input_list = test_case[0]
    number = test_case[1]
    if linear_search(input_list, number) == rotated_array_search(input_list, number):
        print("Pass")
    else:
        print("Fail")


test_function([[6, 7, 8, 9, 10, 1, 2, 3, 4], 6])
test_function([[6, 7, 8, 9, 10, 1, 2, 3, 4], 1])
test_function([[6, 7, 8, 1, 2, 3, 4], 8])
test_function([[6, 7, 8, 1, 2, 3, 4], 1])
test_function([[6, 7, 8, 1, 2, 3, 4], 10])
test_function([[], 0])
test_function([[88], 88])
test_function([[], None])