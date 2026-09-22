# https://codeforces.com/contest/2077/problem/A

for _ in range(int(input())):
    n = int(input())
    a = list(map(int, input().split()))
    a=sorted(a)

    a1 = a[:n-1]
    a2 = a[n-1:]
    x = sum(a2) - sum(a1)

    ord = []

    a1.append(x)

    first= a2.pop()
    ord.append(first)

    for i in range(n):
        ord.append(a1[i])
        ord.append(a2[i])
    print(*ord)
