// https://codeforces.com/contest/2138/problem/A

for _ in range(int(input())):
    n, x = map(int, input().split())
    y = (1<<n+1)-x

    a = [x,y]
    ans = []

    while x!=y:
        if x > y:
            x-=y
            y*=2
            ans.append(2)
        else:
            y-=x
            x*=2
            ans.append(1)

    print(len(ans))
    print(*ans[::-1])