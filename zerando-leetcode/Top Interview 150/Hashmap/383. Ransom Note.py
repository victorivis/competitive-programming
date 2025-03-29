from collections import defaultdict

class Solution(object):
    def canConstruct(self, ransomNote, magazine):
        m1 = defaultdict(int)
        m2 = defaultdict(int)

        for i in ransomNote:
            m1[i]+=1
        for i in magazine:
            m2[i]+=1
        
        for key in m1.keys():
            if m1[key] > m2[key]:
                return False
        return True