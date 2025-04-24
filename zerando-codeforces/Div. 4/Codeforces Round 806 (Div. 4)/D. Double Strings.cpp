/* https://codeforces.com/contest/1703/problem/D */

#include <bits/stdc++.h>
using namespace std;

int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    
    int t; cin >> t;
    while(t--){
        int n; cin >> n;
        set<string> listas;
        vector<string> palavras(n);
        
        for(int i=0; i<n; i++){
            cin >> palavras[i];
            listas.insert(palavras[i]);
        }
        
        vector<bool> possiveis(n, false);
        
        for(int i=0; i<palavras.size(); i++){
            for(int j=1; j<palavras[i].size(); j++){
                bool a = (listas.find(palavras[i].substr(0, j)) != listas.end());
                bool b = (listas.find(palavras[i].substr(j, palavras[i].size()-j)) != listas.end());
                if(a&&b){
                    possiveis[i]=true;
                    break;
                }
            }
        }
        
        for(bool i: possiveis){
            cout << i;
        }
        cout << "\n";
    }

    return 0;
}