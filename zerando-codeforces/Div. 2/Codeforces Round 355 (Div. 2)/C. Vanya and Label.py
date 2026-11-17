# https://codeforces.com/contest/677/problem/C

def conv(c: str):
    x = ord(c)
    if ord('0')<=x<=ord('9'):
        return x-ord('0')

    if ord('A')<=x<=ord('Z'):
            return x-ord('A')+10

    if ord('a')<=x<=ord('z'):
        return x-ord('a')+36

    if c == '-':
        return 62

    if c == '_':
        return 63

    assert(False)

m = 10**9+7

def solve():
    s = input()
    ans = 1

    for x in s:
        val = conv(x)

        for j in range(6):
            if(~val>>j&1):
                ans = ans*3%m
    print(ans)


solve()