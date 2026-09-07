// https://codeforces.com/contest/2065/problem/C2

from bisect import bisect_left as lb

def is_sorted(a):
    return (all(a[i-1] <= a[i] for i in range(1, len(a))))

INF = (1<<40)
def solve():
    n, m = map(int, input().split())
    a = list(map(int, input().split()))
    b = list(map(int, input().split()))
    b = sorted(b)

    lst = -INF

    for i in range(n):
        pos = lb(b,lst+a[i])
        novo = b[pos]-a[i] if pos<m else -INF

        if a[i]>=lst and novo>=lst:
            a[i] = min(a[i], novo)
        else:
            a[i] = max(a[i], novo)
        lst = a[i]

    if is_sorted(a):
        print("YES")
    else:
        print("NO")

for _ in range(int(input())):
    solve()