"""
https://leetcode.com/problems/jump-game-ii/description/?envType=study-plan-v2&envId=top-interview-150
"""

class Solution(object):
    INF = 1e7
    def calcDP(self, nums, pos):
        if pos<len(nums):
            if dp[pos]==-1:
                num = nums[pos]
                menor = self.INF
                for i in range(pos+1, min(len(nums), pos+num+1)):
                    menor = min(menor, 1+self.calcDP(nums, i))
                dp[pos]=menor

            return dp[pos]
        else:
            return self.INF

    def jump(self, nums):
        global dp
        dp = [-1]*len(nums)
        dp[-1]=0

        return self.calcDP(nums, 0)