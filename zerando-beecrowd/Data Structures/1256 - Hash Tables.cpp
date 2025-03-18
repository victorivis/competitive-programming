/*
https://judge.beecrowd.com/en/runs/code/43497786
*/

#include <bits/stdc++.h>
using namespace std;

const int tam = 1e6+3;

int main() {
    int t; cin >> t;
    while(t--){
        int mod, q; cin >> mod >> q;
        vector<int> lista(q);
        
        for(int i=0; i<q; i++){
            cin >> lista[i];
        }
        
        vector<vector<int>> hashtable(mod);
        
        for(int i: lista){
            hashtable[i%mod].push_back(i);
        }
        
        for(int i=0; i<mod; i++){
            cout << i << " -> ";
            
            for(int j=0; j<hashtable[i].size(); j++){
                cout << hashtable[i][j] << " -> ";
            }
            
            cout << "\\\n";
        }
        
        if(t!=0) cout << "\n";
    }
    
    return 0;
}