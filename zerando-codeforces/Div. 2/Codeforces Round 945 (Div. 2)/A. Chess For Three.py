# https://codeforces.com/contest/1973/problem/A

def solve():
    a = list(map(int, input().split()))
    a.sort()

    soma = sum(a)
    if soma&1:
        print(-1)
        return

    mx = max(a)
    ans = min(soma>>1, soma-mx)
    print(ans)
    

for _ in range(int(input())):
    solve()