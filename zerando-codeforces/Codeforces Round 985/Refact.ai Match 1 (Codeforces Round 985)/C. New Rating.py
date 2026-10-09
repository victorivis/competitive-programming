# https://codeforces.com/contest/2029/problem/C

def solve():
    n = int(input())
    a = list(map(int, input().split()))

    def func(x, pos):
        nonlocal a
        if x < a[pos]: return x+1
        if x > a[pos]: return x-1
        return x

    dp = [[0]*(n+1) for i in range(3)]
    for i in range(n):
        dp[0][i+1] = func(dp[0][i], i)
        dp[1][i+1] = max(dp[0][i], dp[1][i])

        if i==0: continue
        dp[2][i+1] = max(func(dp[1][i], i), func(dp[2][i], i))

    print(max(dp[1][n], dp[2][n]))

for _ in range(int(input())):
    solve()