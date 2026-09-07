// https://codeforces.com/contest/2065/problem/C1

def is_sorted(a):
    return (all(a[i-1] <= a[i] for i in range(1, len(a))))

def solve():
    n, _ = map(int, input().split())
    temp = list(map(int, input().split()))
    b = int(input())

    a = [temp, list(map(lambda x: b-x, temp))]

    dp = [[True]*n for i in range(2)]

    for i in range(1, n):
        a1 = a[0][i-1]
        a2 = a[1][i-1]

        c1 = a[0][i]
        c2 = a[1][i]
        dp[0][i] = (a1<=c1 and dp[0][i-1]) or (a2<=c1 and dp[1][i-1])
        dp[1][i] = (a1<=c2 and dp[0][i-1]) or (a2<=c2 and dp[1][i-1])


    if dp[0][-1] or dp[1][-1]:
        print("YES")
    else:
        print("NO")
    

for _ in range(int(input())):
    solve()