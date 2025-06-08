/*
https://cses.fi/problemset/task/1716
*/

#include <bits/stdc++.h>
using namespace std;
 
#define int long long
 
const int modulo = 1e9+7;
const int LIM=2e6+4;
int fatorial[LIM];
 
int lg2(int num){
    int cont=0;
    while(num>0){
        num/=2;
        cont++;
    }
    return cont;
}
 
int exponenciacaoBinaria(int a, int b){
    if(b==0) return 1;
    int metade = exponenciacaoBinaria(a, b/2);
    int total = metade * metade;
    if(b%2==1) total *= a;
    
    return total;
}
 
 
int exponenciacaoBinariaResto(int a, int b, int r){
    long long res = 1;
    while (b > 0) {
        if (b & 1)
            res = (res * a)%r;
        a = (a * a)%r;
        b >>= 1;
    }
    return res;
}
 
int totiente(int n){
    int total=n;
    
    for(int i=2; i<=sqrt(n); i++){
        if(n%i==0){
            while(n%i==0){
                n/=i;
            }
            total-=total/i;
        }
    }
    if(n!=1){
        total-=total/n;
    }
    
    return total;
}
 
int inversoModular(int n, int p){
    static int potencia = totiente(p);
    return exponenciacaoBinariaResto(n, potencia-1, p);
}
 
long long combinacao(long long n, long long p){
    long long denominador = (fatorial[p]*fatorial[n-p])%modulo;
    return (fatorial[n] * inversoModular(denominador, modulo))%modulo;
}
 
int32_t main(){
    fatorial[0]=fatorial[1]=1;
    for(int i=2; i<LIM; i++){
        fatorial[i]=(i*fatorial[i-1])%modulo;
    }
    
    int n, m; cin >> n >> m;
    int total = combinacao(m+n-1, m);
    cout << total << "\n";
 
    return 0;
}