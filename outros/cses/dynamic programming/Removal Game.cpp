/*
https://cses.fi/problemset/task/1097/
*/

#include <bits/stdc++.h>
using namespace std;

vector<vector<long long>> dp;

vector<int> lista;
vector<long long> prefixo;

long long intervalo(int l, int r){
    return prefixo[r+1] - prefixo[l];
}

int main(){
    int n; cin >> n;
    lista.assign(n, 0);
    prefixo.assign(n+1, 0);
    dp.assign(n+1, vector<long long>(n+1, 0));
    
    for(int i=0; i<n; i++){
        cin >> lista[i];
        prefixo[i+1] = prefixo[i] + lista[i];
    }
    
    for(int i=0; i<n; i++){
        dp[i][i] = lista[i];
    }
    
    for(int i=1; i<n; i++){
        for(int j=0; j<n-i; j++){
            int l = j;
            int r = j+i;
            
            long long esquerda = lista[l] + (intervalo(l+1, r) - dp[l+1][r]);
            long long direita = lista[r] + (intervalo(l, r-1) - dp[l][r-1]);
            
            dp[l][r] = max(esquerda, direita);
        }
    }
    
    cout << dp[0][n-1] << "\n";
    
    return 0;
}