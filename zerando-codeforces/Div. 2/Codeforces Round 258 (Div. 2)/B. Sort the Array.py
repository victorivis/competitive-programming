# https://codeforces.com/contest/451/problem/B

n = int(input())
a = list(map(int,input().split()))

b = sorted(a)
d = {}
for i in range(n):
    d[a[i]] = 0

d = dict(sorted(d.items()))

cont = 0
for x in d:
    d[x] = cont
    cont+=1

for i in range(n):
    a[i] = d[a[i]]

b = sorted(a)

l=-1
r=-1

for i in range(len(a)):
    if b[i] != a[i]:
        if l==-1: l=i
        r = i+1

if(l==-1 and r==-1):
    l=0
    r=1

novo = a[:l] + a[l:r][::-1] + a[r:]
if(all(novo[i-1]<=novo[i] for i in range(1,n))):
    print("yes")
    print(l+1,r)
else:
    print("no")