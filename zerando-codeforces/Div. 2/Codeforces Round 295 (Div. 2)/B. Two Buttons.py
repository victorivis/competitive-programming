# https://codeforces.com/contest/520/problem/B

x,y = map(int, input().split())
ans = 0
while(x!=y):
    if(y<x or y&1): y+=1
    else: y>>=1
    ans+=1
print(ans)