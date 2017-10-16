def Max_Kadane(nums):
        res, current_max = float("-inf"), 0 
        for number in nums: # Each step we decide if it's better to add the element or start over 
            current_max = max(current_max + number, number)
            res = max(current_max, res)
        
        return res
  
# Driver function to check the above function 
arr = [-13, -3, -25, -20, -3, -16, -23, -12, -5, -22, -15, -4, -7]
max_sum = Max_Kadane(arr)
print ("Max contiguous subarray {}".format(max_sum))
