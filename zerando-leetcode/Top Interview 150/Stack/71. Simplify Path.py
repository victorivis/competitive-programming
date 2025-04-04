"""
https://leetcode.com/problems/simplify-path/?envType=study-plan-v2&envId=top-interview-150
"""

class Solution(object):
    def simplifyPath(self, path):
        """
        :type path: str
        :rtype: str
        """

        b = path.split('/')
        result = []

        for i in b:
            if i=='..':
                if len(result)!=0:
                    result.pop()
            elif i!='.' and i!='':
                result.append(i)
        
        result = '/'.join(result)
        result = '/'+result

        return result