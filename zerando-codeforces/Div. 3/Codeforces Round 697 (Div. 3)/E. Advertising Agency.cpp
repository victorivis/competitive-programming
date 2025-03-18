/* https://codeforces.com/contest/1475/problem/E */

#include <bits/stdc++.h>
using namespace std;

#define int long long

int exponenciacaoBinaria(int a, int b){
    if(b==0) return 1;
    int metade = exponenciacaoBinaria(a, b/2);
    int total = metade * metade;
    if(b%2==1) total *= a;
    
    return total;
}


int exponenciacaoBinariaResto(int a, int b, int r){
    if(b==0) return 1;
    int metade = exponenciacaoBinariaResto(a, b/2, r) % r;
    int total = (metade * metade)%r;
    if(b%2==1) total = (total * a) % r;
    
    return total;
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
    int potencia = totiente(p);
    return exponenciacaoBinariaResto(n, potencia-1, p);
}

const int modulo = 1e9+7;
const int lim = 1010;
int32_t main(){
    //printf("%d\n\n", modulo);
    
    vector<long long> fat(lim, 1);
    for(int i=1; i<lim; i++){
        fat[i] = (fat[i-1] * i)%modulo;
        //cout << fat[i] << " ";
    }
    //cout << "\n";
    
    int t; cin >> t;
    while(t--){
        int n, k; cin >> n >> k;
        vector<int> quantidades(n+1, 0);
        vector<int> lista(n, 0);
        for(int i=0; i<n; i++){
            int x; cin >> x;
            quantidades[x]++;
            lista[i]=x;
        }
        sort(lista.begin(), lista.end(), greater<int>());
        
        map<int, int> posicoes;
        for(int i=0; i<k; i++){
            int atual = lista[i];
            posicoes[atual]++;
        }
        
        long long total=1ll;
        for(auto& par: posicoes){
            int rep = quantidades[par.first];
            int den = (fat[rep-par.second] * fat[par.second]) % modulo;
            
            //cout << "(" << rep << ", " << den << ") ";
            int inverso = inversoModular(den, modulo);
            //cout << "" << inverso << "," << fat[rep-den] << ") ";
            
            long long iteracao = (fat[rep] * inverso) % modulo;
            total = (total*iteracao) % modulo;
        }
        cout << total << "\n";
    }

    return 0;
}