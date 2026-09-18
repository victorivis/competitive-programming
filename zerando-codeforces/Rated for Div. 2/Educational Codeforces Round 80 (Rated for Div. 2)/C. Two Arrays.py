# https://codeforces.com/problemset/problem/1288/C

MOD = int(1e9)+7
LIM = int(2e6)+5

fat = [1]*(LIM+2)
for i in range(1,LIM):
    fat[i] = i*fat[i-1]%MOD

def inv(num):
    return pow(num,MOD-2,MOD)

def comb(n,m):
    if m>n: return 0
    return fat[n]*inv(fat[m]*fat[n-m]%MOD)%MOD

n,m = map(int,input().split())
print(comb(2*m+n-1, 2*m))