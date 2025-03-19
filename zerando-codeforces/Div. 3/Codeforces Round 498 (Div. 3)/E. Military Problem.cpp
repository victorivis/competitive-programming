/* https://codeforces.com/contest/1006/problem/E */

#include <bits/stdc++.h>
using namespace std;

int contador=1;
vector<int> ordem;
vector<int> altura;
vector<int> irmaos;

void dfs(vector<vector<int>>& grafo, int n, int altura){
    ordem[n]=contador++;
    
    int tamanho = grafo[n].size();
    
    for(int i=0; i<tamanho; i++){
        if(i!=tamanho-1) irmaos[grafo[n][i]] = grafo[n][i+1];
        else irmaos[grafo[n][i]] = -1;
    }
    
    for(int i=0; i<grafo[n].size(); i++){
        dfs(grafo, grafo[n][i], altura+1);
    }
    
    irmaos[n]=contador;
}

int main(){
    int n, q; cin >> n >> q;
    vector<vector<int>> grafo(n+1);
    for(int i=2; i<=n; i++){
        int x; cin >> x;
        grafo[x].push_back(i);
    }
    
    for(int i=1; i<grafo.size(); i++){
        sort(grafo[i].begin(), grafo[i].end());
    }
    
    ordem.assign(n+1, 0);
    altura.assign(n+1, 0);
    irmaos.assign(n+1, 0);
    
    irmaos[1]=n+1;
    dfs(grafo, 1, 1);
    
    vector<int> ordemParaIndice(n+1);
    for(int i=1; i<=n; i++){
        ordemParaIndice[ordem[i]] = i;
    }
    
    while(q--){
        int oficial, posicao; cin >> oficial >> posicao;
        
        int desejado = ordem[oficial] + posicao - 1;
        int limite = irmaos[oficial];
        
        if(desejado < limite){
            cout << ordemParaIndice[desejado] << "\n";
        }
        else{
            cout << "-1\n";
        }
    }

    return 0;
}