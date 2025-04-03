"""
https://leetcode.com/problems/zigzag-conversion/description/?envType=study-plan-v2&envId=top-interview-150
"""

class Solution(object):
    def convert(self, s, numRows):
        """
        :type s: str
        :type numRows: int
        :rtype: str
        """
        if(numRows==1):
            return s

        result=s[::numRows*2-2]
        for i in range(1, numRows-1):
            atual=i
            cont=0
            l = [(numRows-i-1)*2, i*2]
            
            while(atual<len(s)):
                result+=s[atual]                
                atual+= l[cont]
                cont = (cont+1)%2
                
        result+=s[numRows-1::numRows*2-2]
        return result