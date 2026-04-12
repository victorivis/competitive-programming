# https://codeforces.com/contest/2185/problem/B

for _ in range(int(input())):
    n = int(input())
    l = list(map(int, input().split()))
    
    print(max(l)*n)