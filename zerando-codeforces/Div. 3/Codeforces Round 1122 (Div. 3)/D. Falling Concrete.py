# https://codeforces.com/contest/2266/problem/D

import sys

input = sys.stdin.readline

oo = 1<<30

for _ in range(int(input())):
    n = int(input())
    a = list(map(int, input().split()))

    st = []
    for i in range(n):
        st.append(a[i]-i)
    st.sort()

    lst = -oo
    acc = 0
    mx = 0
    for x in st:
        if x == lst: continue

        if x == lst+1:
            acc+=1
        else:
            acc=1
        lst=x
        mx = max(mx, acc)
    print(mx)