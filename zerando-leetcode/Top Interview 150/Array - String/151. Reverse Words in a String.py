"""
https://leetcode.com/problems/reverse-words-in-a-string/description/?envType=study-plan-v2&envId=top-interview-150
"""

class Solution(object):
    def reverseWords(self, s):
        """
        :type s: str
        :rtype: str
        """

        novo = s.split()
        novo = novo[::-1]
        novo = " ".join(novo)
        return novo