/* https://codeforces.com/contest/1703/problem/E */

#include <bits/stdc++.h>
using namespace std;

int main(){
    
    int t; cin >> t;
    while(t--){
        int n; cin >> n;
        vector<string> lista(n);
        
        for(int i=0; i<n; i++){
            cin >> lista[i];
        }
        
        int total=0;
        
        int inicio=0, fim=n-1;
        while(inicio<fim){
            int cont=0;
            for(int i=inicio; i<fim; i++, cont++){
                int local = lista[i][inicio] - '0';
                   local += lista[fim][i] - '0';
                   local += lista[fim-cont][fim] - '0';
                   local += lista[inicio][fim-cont] - '0';
                
                int totalLocal = min(local, 4-local);
                
                total += totalLocal;
            }
            inicio++; fim--;
        }
        
        cout << total << "\n";
    }

    return 0;
}