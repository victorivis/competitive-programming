"""
https://leetcode.com/problems/is-subsequence/description/?envType=study-plan-v2&envId=top-interview-150
"""

class Solution(object):
    def isSubsequence(self, s, t):
        pS = 0
        pT = 0

        while pS < len(s) and pT<len(t):
            if s[pS] == t[pT]:
                pS+=1
            pT+=1
        
        return pS==len(s)