# https://codeforces.com/contest/2065/problem/D


def rec(a):
    n = len(a)
    partes = []
    acc = 0
    for i in range(n):
        acc += a[i]
        partes.append(acc)
    return sum(partes)

def solve():
    n, m = map(int, input().split())
    a = []
    b = []

    for i in range(n):
        c = list(map(int, input().split()))
        a.append(c)

        b.append((sum(c),i,))
    b = sorted(b, reverse=True)

    arr = []
    for x in b:
        arr += a[x[1]]

    print(rec(arr))

for _ in range(int(input())):
    solve()