/* https://codeforces.com/contest/2098/problem/B */

#include <bits/stdc++.h>
using namespace std;

vector<int> lista;
vector<bool> vis;
int funcao(int num){
    int total=0;
    for(int i=0; i<lista.size(); i++){
        total += vis[i] ? abs(num - lista[i]) : 0;
    }
    return total;
}

int32_t main(){
    int t; cin >> t;
    while(t--){
        int n, k; cin >> n >> k;
        lista.assign(n, 0);
        vis.assign(n, 0);
        
        for(int i=0; i<n; i++){
            cin >> lista[i];
        }
        sort(lista.begin(), lista.end());
        
        int tam = lista.size();
        int resposta;
        if(tam%2==1){
            int meio = tam/2;
            
            int passos = (k+1)/2;
            int l = max(0, meio-passos);
            int r = min(n-1, meio+passos);
            resposta = lista[r] - lista[l] + 1;
        }
        else{
            int passos = k/2;
            
            int l = tam/2 - 1;
            int r = tam/2;
            
            l = max(0, l-passos);
            r = min(n-1, r+passos);
            
            resposta = lista[r] - lista[l] + 1;
        }
        
        cout << resposta << "\n";
    }
    
    return 0;
}