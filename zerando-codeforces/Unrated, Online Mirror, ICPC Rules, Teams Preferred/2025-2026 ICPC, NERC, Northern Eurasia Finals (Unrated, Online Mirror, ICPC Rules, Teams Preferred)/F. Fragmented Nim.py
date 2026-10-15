# https://codeforces.com/contest/2181/problem/F

for _ in range(int(input())):
    n = int(input())
    a = list(map(int, input().split()))

    ans = (a.count(1)+int(max(a)>=2))&1
    
    print("Alice" if ans else "Bob")