/*
https://codeforces.com/contest/2086/problem/B
*/

#include <bits/stdc++.h>
using namespace std;

void mostrar(vector<long long>& l){
    for(long long i: l){
        cout << i << " ";
    }
    cout << "\n";
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    int t; cin >> t;
    while(t--){
        long long n, k, x; cin >> n >> k >> x;
        
        vector<int> lista(n);
        vector<long long> prefixo(n+1, 0);
        for(int i=0; i<n; i++){
            int x; cin >> x;
            prefixo[i+1] = prefixo[i] + x;
            lista[i]=x;
        }
        
        long long total=0;
        if(prefixo[n]*k >= x){
            long long pos = x/prefixo[n];
            long long resto = x%prefixo[n];            
            long long parteInteira = (k-pos-1) * n;
            
            long long objetivo = prefixo[n] - resto;
            
            auto binario = upper_bound(prefixo.begin(), prefixo.end(), objetivo);
            int posValidas = binario-prefixo.begin();
            
            total = parteInteira + posValidas;
        }
        
        
        
        cout << total << "\n";
    }
    
    return 0;
}