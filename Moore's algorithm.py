def majority_element(nums):
    """
    Returns the majority element in a given list using Moore's Voting Algorithm.
    
    Args:
    nums (list): List of integers.
    
    Returns:
    int: Majority element, if it exists. None otherwise.
    """
    # initialize variables
    candidate = None
    count = 0
    
    # iterate through list
    for num in nums:
        if count == 0:
            # set new candidate
            candidate = num
        count += 1 if num == candidate else -1
    
    # verify candidate is actually the majority element
    if nums.count(candidate) > len(nums) // 2:
        return candidate
    else:
        return None
nums = [2,2,1,1,1,2,2]
print(majority_element(nums)) # output: 2

nums = [3,3,4,2,4,4,2,4,4]
print(majority_element(nums)) # output: 4

nums = [1,2,3,4,5]
print(majority_element(nums)) # output: None
