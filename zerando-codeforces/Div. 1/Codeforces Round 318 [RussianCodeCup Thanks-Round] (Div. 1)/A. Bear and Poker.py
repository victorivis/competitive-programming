# https://codeforces.com/contest/573/problem/A

n = int(input())
a = list(map(int,input().split()))

for i in range(n):
    while a[i]%2==0: a[i]/=2
    while a[i]%3==0: a[i]/=3

print("Yes" if a.count(a[0]) == n else "No")