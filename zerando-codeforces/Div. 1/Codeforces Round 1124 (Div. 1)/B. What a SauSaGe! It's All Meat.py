# https://codeforces.com/contest/2268/problem/B

alvos = set([15,12,9,6,3,0,5,10])

for _ in range(int(input())):
    n, q = map(int, input().split())
    a = list(map(int, input().split()))

    ans = 0
    for x in a:
        ans += (x in alvos)

    print(ans,end=' ')
    for __ in range(q):
        x,y = map(int, input().split())
        ans -= (a[x-1] in alvos)
        a[x-1] = y
        ans += (a[x-1] in alvos)
        print(ans,end=' ')
    print()