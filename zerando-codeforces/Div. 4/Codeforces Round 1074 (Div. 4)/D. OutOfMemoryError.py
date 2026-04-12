# https://codeforces.com/contest/2185/problem/D

t = int(input())
out_lines = []
for _ in range(t):
    n, m, h = map(int, input().split())
    backup = list(map(int, input().split()))
    lista = [0] * n
    
    
    tempos = [0]*n
    cur_tempo = 1

    for __ in range(m):
        pos, val = map(int, input().split())
        pos-=1
        
        if tempos[pos] != cur_tempo:
            lista[pos] = backup[pos]
            tempos[pos] = cur_tempo
        if lista[pos] > h:
            cur_tempo += 1
        lista[pos] += val
        if lista[pos] > h:
            cur_tempo += 1
        
    for i in range(n):
        if tempos[i] != cur_tempo:
            lista[i] = backup[i]
            tempos[i] = cur_tempo
        if lista[i] > h:
            cur_tempo += 1
        print(lista[i], end=' ')
    print()