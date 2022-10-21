"""
Description

You are given N elements, in an array A. You can take any 2 consecutive elements a and b and merge them. On merging you get a single element with value (a+b)%100 and this process costs you a*b. After merging you will place this element in place of those 2 elements.
 

If the sequence is [A1, A2, A3, A4] and you merge A2 and A3, you incur a cost of A2*A3 and the array becomes [A1, (A2+A3)%100, A4].
 

Find the Minimum cost to merge all the elements into a single element.
"""

def mergeElements(l, r,ans):
    if l == r:
        return 0

    if dp[l][r] == -1:
        total = 0
        for i in range(l, r + 1):
            total += arr[i]

        summ = 0
        for mid in range(l, r):
           summ += arr[mid]
           ans = min(ans,mergeElements(l, mid)+ mergeElements(mid + 1, r)+ (summ) * (total - summ))

        dp[l][r] = ans
    return dp[l][r]


n = int(input())
arr = [int(x) for x in input().split()]
dp = [[-1 for i in range(4001)] for j in range(4001)]
print(mergeElements(0, n - 1))


"""
The nice observation here is the value of the Final element remains fixed and is the sum of the range %100.

So we can design a DP with the states
DP(l,r) = minimum cost to merge the segment into one element.

Now range (l,r) will form one element from 2 elements in the final step.
So let's say the (l, mid) and (mid+1,r) range equivalents merge and produce the final element.

So DP(l,r) = min(DP(l,mid) + DP(mid+1,r) + (sum(l,mid)%100)*(sum(mid+1,r)%100) ) for all mid in range [l,r).

"""
