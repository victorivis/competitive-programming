# https://codeforces.com/contest/2185/problem/C

for _ in range(int(input())):
    n = int(input())
    li = list(map(int, input().split()))
    
    li.sort()
    li = list(dict.fromkeys(li).keys())

    maior = 0
    pos = li[0]
    atual = 0

    for num in li:
        if num == pos:
            atual += 1
            pos += 1
        else:
            atual = 1
            pos = num+1

        maior = max(maior, atual)
    print(maior)