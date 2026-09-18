# https://codeforces.com/problemset/problem/1332/B

LIM = 1001

val = [-1]*(LIM+1)
primos = []
def crivo(n):
    for i in range(2,n+1):
        if(val[i]==-1):
            val[i] = 0
            primos.append(i)

            for j in range(i,n+1,i):
                if(val[j]==-1):
                    val[j]=1

crivo(LIM)

def outro(n, lista, cores):
    for i in range(2,n+1):
        if(val[i]==0):
            cont = 0
            for j in range(i,n+1,i):
                if(lista[j]>0):
                    lista[j]=0
                    cont+=1
            if cont:
                cores.append(i)

t = int(input())

lista = [0]*(LIM+2)
for _ in range(t):
    n = int(input())
    a = list(map(int,input().split()))

    for x in a:
        lista[x]+=1

    cores = []
    outro(LIM,lista,cores)

    assert(len(cores)<=11)
    print(len(cores))
    for x in a:
        for i in range(len(cores)):
            if(x%cores[i]==0):
                print(i+1, end=' ')
                break
    print()