"""
Problem: 712. Minimum ASCII Delete Sum for Two Strings

Given two strings s1 and s2, return the lowest ASCII 
sum of deleted characters to make two strings equal.

Platform: LeetCode
Link: https://leetcode.com/problems/minimum-ascii-delete-sum-for-two-strings/
Performance: 85 % faster, 75 % less memory (relative)
Easy to read
"""

class Solution:
    def minimumDeleteSum(self, s1: str, s2: str) -> int:
        '''
        Problem statement: the lowest ASCII sum
        of deleted elements to obtain LCS
        = find the Highest ASCII sum of the LCS
        And let's call it 'x'
        Then our answer is sum of ascii chars of s1 and s2
        minus 2 * x
        '''
        
        # Redifined LCS to obtain highest sum ASCII LCS
        def lcs(X , Y):
            # find the length of the strings
            m = len(X)
            n = len(Y)

            # declaring the array for storing the dp values
            L = [[None]*(n+1) for i in range(m+1)]

            """Following steps build L[m+1][n+1] in bottom up fashion
            Note: L[i][j] contains maximum ascii sum of LCS of X[0..i-1]
            and Y[0..j-1]"""
            for i in range(m+1):
                for j in range(n+1):
                    
                    # Base case
                    if i == 0 or j == 0 :
                        L[i][j] = 0
                    
                    # If two characters are matching then
                    # The formed LCS can have heigst sum
                    # Or We have previously obtained the 
                    # Heigest sum of ascii characters
                    # We need the max only
                    elif X[i-1] == Y[j-1]:
                        L[i][j] = max(L[i-1][j-1]+ord(X[i-1]), L[i-1][j] , L[i][j-1])
                    
                    # Else get the max without the character
                    else:
                        L[i][j] = max(L[i-1][j] , L[i][j-1])
            return L[m][n]
        
        # Find the sum of all the ASCII values of 's1' chars
        r1 = 0
        for i in s1:
            r1 += ord(i)
        
        # Find the sum of all the ASCII values of 's2' chars
        r2 = 0
        for i in s2:
            r2 += ord(i)
        
        # Return the answer
        return r1 + r2 - 2 * lcs(s1, s2)

