class Solution:
    def bubbleSortOptimized(self, nums: list[int]) -> None:
        if len(nums) == 1:
            return nums
        else:
            swapped = False
            while not swapped:
                swapped = True
                for i in range(0, len(nums)-1):
                    if nums[i] > nums[i+1]:
                        swapped = False
                        nums[i], nums[i+1] = nums[i+1], nums[i]
