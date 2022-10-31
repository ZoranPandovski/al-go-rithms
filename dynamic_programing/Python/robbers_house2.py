def rob(self, nums: List[int]) -> int:
    def rm(num):
        if len(num) ==1 or len(num) == 2:
            return max(num)

    num[1] = max(num[0], num[1])
    for i in range(2, len(num)):
        num[i] = max(num[i] + num[i-2], num[i-1])

    return num[-1]

    if len(nums) == 1:
        return nums[0]
    return max(rm(nums[:-1]), rm(nums[1:]))