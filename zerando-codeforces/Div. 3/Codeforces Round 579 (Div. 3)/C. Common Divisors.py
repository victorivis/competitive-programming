# https://codeforces.com/contest/1203/problem/C

from math import sqrt, gcd

def div(num):
    a = []
    for i in range(1,int(sqrt(num))+1):
        if num%i==0:
            a.append(i)
            if i != num//i:
                a.append(num//i)
    return len(a)

n = int(input())
a = list(map(int,input().split()))

print(div(gcd(*a)))