/*
https://br.spoj.com/problems/ELEICOES/
*/

#include <bits/stdc++.h>
using namespace std;
 
int main() {
    int t; cin >> t;
    map<int, int> d;
    while(t--){
        int x; cin >> x;
        d[x]++;
    }
    
    int vencedor=0;
    int votos=0;
    
    for(auto& par: d){
        if(par.second > votos){
            vencedor=par.first;
            votos=par.second;
        }
    }
    
    cout << vencedor << "\n";
    
    return 0;
} 