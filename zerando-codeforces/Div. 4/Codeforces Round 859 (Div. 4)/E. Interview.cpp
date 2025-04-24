/* https://codeforces.com/contest/1807/problem/E */

#include <bits/stdc++.h>
using namespace std;

int main(){
    int t; cin >> t;
    while(t--){
        int n; cin >> n;
        vector<long long> prefixo(n+1, 0);
        
        for(int i=0; i<n; i++){
            int x; cin >> x;
            prefixo[i+1] = prefixo[i] + x;
        }
        
        int posicao=-1;
        int l=1, r=n;
        while(l<r){
            int meio = (l+r)/2;
            
            int intervalo = meio - l + 1;
            
            //fazer a pergunta
            cout << "? " << intervalo;
            for(int i=l; i<=meio; i++){
                cout << " " << i;
            }
            cout << "\n";
            cout.flush();
            
            int resposta; cin >> resposta;
            if(prefixo[meio] - prefixo[l-1] == resposta){
                l = meio+1;
            }
            else{
                r = meio;
            }
        }
        cout << "! " << (l+r)/2 << "\n";
        cout.flush();
    }
    
    return 0;
}