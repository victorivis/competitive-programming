"""
https://leetcode.com/problems/product-of-array-except-self/?envType=study-plan-v2&envId=top-interview-150
"""

class Solution(object):
    def productExceptSelf(self, nums):
        product=1
        countZero=0
        posZero=-1

        for index, num in enumerate(nums):
            if num!=0:
                product*=num
            else:
                posZero=index
                countZero+=1
        
        if countZero==1:
            result = [0]*len(nums)
            result[posZero] = product
        elif countZero>=2:
            result = [0]*len(nums)
        else:
            result = []
            for i in nums:
                result.append(product/i)

        return result