# https://codeforces.com/problemset/problem/2062/C

for _ in range(int(input())):
    n = int(input())
    a = list(map(int, input().split()))
    
    maior = sum(a)
    while len(a)>1:
        a = [a[i]-a[i-1] for i in range(1,len(a))]
        acc = sum(a)
        
        maior = max(maior, abs(acc))
    
    print(maior)