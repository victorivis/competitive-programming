# https://codeforces.com/contest/2185/problem/E

import bisect

INF = int(2e9)

for _ in range(int(input())):
    n, m, k = map(int, input().split())
    
    robot = list(map(int, input().split()))
    spikes = list(map(int, input().split()))
    ordens = list(input())
    
    robot.sort()
    spikes.sort()
    
    tudo = [[x, 0] for x in robot] + [[x, 1] for x in spikes]
    tudo.sort()
    
    d = {}
    for num in robot:
        d[num] = [-INF, INF]

    pilha = []
    cur = -INF
    for i in range(len(tudo)):
        if tudo[i][1]==0:
            val = tudo[i][0]
            d[val][0] = cur-val
            pilha.append(val)
            continue
        
        cur = tudo[i][0]
        for num in pilha:
            d[num][1] = cur-num
        pilha.clear()
    
    decrescente = [INF] * (k+2)
    crescente = [-INF] * (k+2)
    
    crescente[-1] = INF
    decrescente[-1] = -INF
    
    acumulado=0
    for i in range(1, k+1):
        acumulado += 1 if ordens[i-1]=='R' else -1
        
        decrescente[i] = min(acumulado, decrescente[i-1])
        crescente[i] = max(acumulado, crescente[i-1])
    
    decrescente = [-x for x in decrescente]
    
    ans = [0] * (k+2)
    
    for val in d.values():
        l = bisect.bisect_left(decrescente, -val[0])
        r = bisect.bisect_left(crescente, val[1])
        
        pos = min(l, r)
        ans[pos] += -1
    
    ans[0] = n
    
    for i in range(1, k+1):
        ans[i] += ans[i-1]
        print(ans[i], end=' ')
    print()