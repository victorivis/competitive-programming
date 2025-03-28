"""
https://leetcode.com/problems/insert-delete-getrandom-o1/description/?envType=study-plan-v2&envId=top-interview-150
"""

import random

class RandomizedSet(object):
    def __init__(self):
        self.mySet = {}

    def insert(self, val):
        if val not in self.mySet:
            self.mySet[val] = True
            return True
        return False

    def remove(self, val):
        if val in self.mySet:
            del self.mySet[val]
            return True
        return False

    def getRandom(self):
        return random.choice(self.mySet.keys())

# Your RandomizedSet object will be instantiated and called as such:
# obj = RandomizedSet()
# param_1 = obj.insert(val)
# param_2 = obj.remove(val)
# param_3 = obj.getRandom()