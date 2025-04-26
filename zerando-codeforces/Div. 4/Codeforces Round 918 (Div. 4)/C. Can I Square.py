""" https://codeforces.com/contest/1915/problem/C """

import functools
import math

t = int(input())
for i in range(t):
    input()
    l = map(int, input().split())
    t = math.sqrt(functools.reduce(lambda x, y: x+y, l))
    if t == int(t):
        print("YES")
    else:
        print("NO")