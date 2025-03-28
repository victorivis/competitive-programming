"""
https://leetcode.com/problems/h-index/description/?envType=study-plan-v2&envId=top-interview-150
"""

class Solution(object):
    def hIndex(self, citations):
        l = 0
        r = len(citations)

        while l<=r:
            mid = (l+r)//2

            count=0
            for num in citations:
                if num>=mid:
                    count+=1
            
            if count>=mid:
                lower=mid
                l=mid+1
            else:
                r=mid-1
        return lower