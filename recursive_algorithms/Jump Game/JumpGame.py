def rec(i):
            if i>len(nums)-1:
                return False
            if i==len(nums)-1:
                return True
            ans=False
            for j in range(i+1,min(i+nums[i],len(nums)-1)+1):
                if rec(j):
                    return True
            return False
nums=list(map(int,input().split()))
print(rec(0))
