/* https://codeforces.com/contest/1829/problem/G */

#include <bits/stdc++.h>
using namespace std;

#define int long long

const int LIM = 2e3+5;
vector<int> prefixo(2e4, 0);
vector<vector<int>> matriz(LIM, vector<int>(LIM, 0));

long long calcular(int n){
    int linha = lower_bound(prefixo.begin(), prefixo.end(), n) - prefixo.begin();
    int pos = n - prefixo[linha-1]-1;
    
    long long total=0;
    while(pos>=0 && linha>=0){        
        total+=matriz[linha][pos];
        
        linha--;
        pos--;
    }
    return total;
}

int32_t main(){
    for(int i=1; i<prefixo.size(); i++){
        prefixo[i] = i*(i+1)/2;
    }
    
    for(int i=1; i<LIM; i++){
        int atual = prefixo[i-1];
        
        for(int j=0; atual+j<prefixo[i]; j++){
            matriz[i][j] = matriz[i-1][j] + (atual+j+1) * (atual+j+1);
        }
    }
    
    int t; cin >> t;
    while(t--){
        int n; cin >> n;
        
        long long total = calcular(n);
        
        cout << total << "\n";
    }

    return 0;
}