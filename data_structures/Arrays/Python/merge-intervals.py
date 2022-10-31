class Solution:
    def merge(self, intervals):
        ans = []
        
        for beg, end in sorted(intervals):
            if not ans or ans[-1][1] < beg:
                ans += [[beg, end]]
            else:
                ans[-1][1] = max(ans[-1][1], end)

        return ans