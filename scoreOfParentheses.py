class Solution(object):
    def scoreOfParentheses(self, S):
        """
        :type S: str
        :rtype: int
        """
        return self.iterate(S, 0)[0]
    def iterate(self, S, idx):
        score = 0
        i = idx
        while i < len(S):
            if S[i] == "(":
                if S[i+1] == "(":
                    i += 1
                    sc, idx = self.iterate(S, i)
                    score += 2 * sc
                    i = idx + 1
                else:
                    score += 1
                    i += 2
            else:
                return (score, i)
        return (score, i)

A = Solution()
print(A.scoreOfParentheses("(()(()))"))