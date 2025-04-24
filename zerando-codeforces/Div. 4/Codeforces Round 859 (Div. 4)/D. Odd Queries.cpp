/* https://codeforces.com/contest/1807/problem/D */

#include <bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    int t; cin >>t;
    while(t--){
        int n, q; cin >> n >> q;
        vector<long long> prefixo(n+1, 0);
        
        for(int i=0; i<n; i++){
            int x; cin >> x;
            prefixo[i+1] = prefixo[i] + x;
        }
        
        while(q--){
            long long l, r, k; cin >> l >> r >> k;
            int intervalo = r - l + 1;
            long long esquerda = prefixo[l-1]-prefixo[0];
            long long direita = prefixo[n]-prefixo[r];
            long long total = esquerda + intervalo*k + direita;
            
            if(total%2==1){
                cout << "YES\n";
            }
            else{
                cout << "NO\n";
            }
        }
    }
    
    return 0;
}