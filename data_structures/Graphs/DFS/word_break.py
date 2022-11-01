def wordBreak(self, s: str, wordDict: List[str]) -> bool:
    n= len(s)
    
    @lru_cache(None)
    def dfs(k):
        if k >=n :
            return True
        
        for i in range(k, n):
            if s[k:i+1] in wordDict and dfs(i+1):
                return True
            
        return False
                
    return dfs(0)