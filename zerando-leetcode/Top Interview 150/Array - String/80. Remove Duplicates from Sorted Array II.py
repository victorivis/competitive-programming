"""
https://leetcode.com/problems/remove-duplicates-from-sorted-array-ii/description/?envType=study-plan-v2&envId=top-interview-150
"""

class Solution(object):
    def removeDuplicates(self, nums):
        dist = 0
        control = {}

        for index, num in enumerate(nums):
            if num not in control:
                control[num]=1
            else:
                control[num]+=1

            if dist>0:
                nums[index], nums[index-dist] = nums[index-dist], nums[index]

            if control[num]>2:
                dist+=1
                
        return len(nums)-dist