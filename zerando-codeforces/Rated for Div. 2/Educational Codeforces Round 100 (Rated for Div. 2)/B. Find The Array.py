# https://codeforces.com/problemset/problem/1463/B

for _ in range(int(input())):
    n = int(input())
    a = list(map(int,input().split()))

    for x in a:
        print(1<<(x.bit_length()-1),end=' ')
    print()