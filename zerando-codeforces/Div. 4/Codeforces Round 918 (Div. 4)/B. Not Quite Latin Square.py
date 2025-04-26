""" https://codeforces.com/contest/1915/problem/B """

import functools

t = int(input())
for i in range(t):
    c = ord('A') ^ ord('B') ^ ord('C') ^ ord('?')
    pos = []
    for j in range(3):
        l = [ord(k) for k in input()]
        
        if ord('?') in l:
            print(chr(functools.reduce(lambda x, y: x^y, l) ^ c))