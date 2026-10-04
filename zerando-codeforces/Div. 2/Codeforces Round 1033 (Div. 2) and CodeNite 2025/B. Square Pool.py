# https://codeforces.com/problemset/problem/2120/B

for _ in range(int(input())):
    n, s = map(int, input().split())
    ans = 0
    for __ in range(n):
        d1,d2,x,y = map(int, input().split())

        if d1==d2:
            ans += (x==y)
        else:
            ans += (x+y==s)
    print(ans)