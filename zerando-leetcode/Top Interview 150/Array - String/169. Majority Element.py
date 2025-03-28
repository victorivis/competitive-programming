"""
https://leetcode.com/problems/majority-element/description/?envType=study-plan-v2&envId=top-interview-150
"""

class Solution(object):
    def majorityElement(self, nums):
        
        count = 0
        currNum = nums[0]

        for i in nums:      
            if i != currNum:
                count-=1
            else:
                count+=1
            if count==0:
                currNum=i
                count+=1
        
        return currNum