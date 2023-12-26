class Solution:
    def climbStairs(self, n: int) -> int:
        
        dp = [-1] * (n + 1)
        
        def climb(n):
            if n == 1:
                return 1
            if n == 2:
                return 2
            
            if dp[n] != -1:
                return dp[n]
            
            val = climb(n-1) + climb(n-2)
            dp[n] = val
            return val
        
        return climb(n)
    
        