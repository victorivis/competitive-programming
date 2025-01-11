/* https://codeforces.com/contest/1872/problem/E */

#include <bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    int t; cin >> t;
    while(t--){
        int n; cin >> n;
        vector<int> prefixo(n+2, 0);
        for(int i=1; i<=n; i++){
            int x; cin >> x;
            prefixo[i] = prefixo[i-1] ^ x;
        }
        
        int um=0;
        int zero=0;
        
        for(int i=1; i<=n; i++){
            char c; cin >> c;
            int atual = prefixo[i] ^ prefixo[i-1];
            
            if(c=='1'){
                um ^= atual;
            }
            else{
                zero ^= atual;
            }
        }
        prefixo[n+1] ^= prefixo[n];
        
        int q; cin >> q;
        while(q--){
            int x; cin >> x;
            if(x==2){
                int binario; cin >> binario;
                
                if(binario==1){
                    cout << um << " ";
                }
                else{
                    cout << zero << " ";
                }
            }
            else{
                int l, r; cin >> l >> r;
                int intervalo = (prefixo[l-1] ^ prefixo[r]);
                
                um ^= intervalo;
                zero ^= intervalo;
            }
        }
        
        cout << "\n";
    }
    
    return 0;
}