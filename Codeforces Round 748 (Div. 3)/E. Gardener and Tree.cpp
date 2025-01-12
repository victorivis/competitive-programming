/* https://codeforces.com/contest/1593/problem/E */

#include <bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    int t; cin >> t;
    while(t--){
        int n, k; cin >> n >> k;
        vector<vector<int>> grafo(n+1);
        for(int i=0; i<n-1; i++){
            int x, y; cin >> x >> y;
            grafo[x].push_back(y);
            grafo[y].push_back(x);
        }
        
        queue<int> segunda;
        vector<int> folhas(n+1, INT_MAX-100);
        vector<int> visitados(n+1, 0);
        vector<int> cortados(n+1, 0);
        queue<int> fila;
        
        fila.push(1);
        visitados[1]=1;
        while(fila.empty()==false){
            int atual=fila.front();
            
            for(int i=0; i<grafo[atual].size(); i++){
                int proximo = grafo[atual][i];
                if(visitados[proximo]==0){
                    visitados[proximo]=1;
                    fila.push(proximo);
                }
            }
            
            if(grafo[atual].size()<=1){
                folhas[atual]=1;
                visitados[atual]=2;
                
                if(grafo[atual].size()==1){
                    int proximo = grafo[atual][0];
                    
                    cortados[proximo]++;
                    if((int) grafo[proximo].size() - cortados[proximo] <= 1){
                        segunda.push(atual);
                    }
                }
            }
            
            fila.pop();
        }
        
        
        while(segunda.empty()==false){
            int atual = segunda.front();
            
            for(int i=0; i<grafo[atual].size(); i++){
                int proximo = grafo[atual][i];
                
                cortados[proximo]++;
                if(visitados[proximo]==1 && ((int) grafo[proximo].size() - cortados[proximo] <= 1)){
                    folhas[proximo] = min(folhas[proximo], folhas[atual]+1);
                    visitados[proximo]=2;
                    segunda.push(proximo);
                }
                
            }
            
            segunda.pop();
        }
        
        int cortes=0;
        for(int i=1; i<=n; i++){
            if(folhas[i] <= k){
                cortes++;
            }
        }
        
        cout << n-cortes << "\n";
    }

    return 0;
}