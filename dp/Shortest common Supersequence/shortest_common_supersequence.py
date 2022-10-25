# Optimized code - DP Top-Down

class Solution:
    def shortestCommonSupersequence(self, str1: str, str2: str) -> str:
        
        m = len(str1)
        n = len(str2)
        
        t = [[-1]*(n+1) for i in range(m+1)]
        
        for i in range(m+1):
            for j in range(n+1):
                if(i==0 or j==0):
                    t[i][j] = 0
        
        for i in range(1, m+1):
            for j in range(1, n+1):
                
                if str1[i-1] == str2[j-1]:
                    t[i][j] = 1 + t[i-1][j-1]
                else:
                    t[i][j] = max(t[i-1][j], t[i][j-1])
        
        o = m
        p = n
        s = ''
        
        while o > 0 and p > 0:
            
            if str1[o-1] == str2[p-1]:
                s = s + str1[o-1]
                o -= 1
                p -= 1
            
            else:
                if t[o-1][p] > t[o][p-1]:
                    o -= 1
                else:
                    p -= 1
        
        s = s[::-1]
        
        res, i, j = "", 0, 0
        
        for a in s:
            while str1[i] != a:
                res += str1[i]
                i+=1
            
            while str2[j] != a:
                res += str2[j]
                j +=1
            res += a
            i+=1
            j+=1
            
        return res + str1[i:] + str2[j:]