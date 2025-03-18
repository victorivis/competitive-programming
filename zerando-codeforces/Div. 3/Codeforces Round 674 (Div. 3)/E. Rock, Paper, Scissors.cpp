/* https://codeforces.com/contest/1426/problem/E */

#include <bits/stdc++.h>
using namespace std;


vector<int> base = {0, 1, 2};
vector<vector<int>> permutacoes;

int contarVitorias(vector<int>& alice, vector<int>& bob, int i, int perm){
    int cont=0;
    int vitorias=0;
    
    while(alice[i]>0){
        int pos = permutacoes[perm][cont++];
        
        int diferenca = min(alice[i], bob[pos]);
        
        if((i+1)%3 == pos){
            vitorias+=diferenca;
        }
            
            alice[i] -= diferenca;
            bob[pos] -= diferenca;
            
            pos = (pos-1+3)%3;
    }
    
    return vitorias;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    do {
        permutacoes.push_back(base);
    } while (next_permutation(base.begin(), base.end()));
    
    int n; cin >> n;
    
    vector<int> alice(3);
    vector<int> bob(3);
    
    for(int i=0; i<3; i++){
        cin >> alice[i];
    }
    for(int i=0; i<3; i++){
        cin >> bob[i];
    }
        
    int vitorias=0;
    
    vector<int> copiaA = alice;
    vector<int> copiaB = bob;
    
    vector<int> totalVitorias;
    
    for(int i=0; i<permutacoes.size(); i++){
        for(int k=0; k<permutacoes.size(); k++){
            alice=copiaA;
            bob=copiaB;
                
            int vitorias=0;
            
            for(int j=0; j<3; j++){
                int atual = permutacoes[k][j];
                
                vitorias += contarVitorias(alice, bob, atual, i);
            }
            
            
            totalVitorias.push_back(vitorias);
        }
    }
        
    sort(totalVitorias.begin(), totalVitorias.end());
    
    int ultima = totalVitorias.size()-1;
    cout << totalVitorias[0] << " " << totalVitorias[ultima] << "\n";
    
    return 0;
}