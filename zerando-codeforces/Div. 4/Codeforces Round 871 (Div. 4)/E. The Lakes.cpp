/* https://codeforces.com/contest/1829/problem/E */

#include <bits/stdc++.h>
using namespace std;

int n, m;
vector<vector<int>> grafo;
vector<vector<bool>> visitados;

int dfs(int i, int j){
    visitados[i][j]=true;
    int total=grafo[i][j];
    
    if(i>0 && visitados[i-1][j]==false && grafo[i-1][j]!=0) total+=dfs(i-1, j);
    if(j>0 && visitados[i][j-1]==false && grafo[i][j-1]!=0) total+=dfs(i, j-1);
    if(i+1<n && visitados[i+1][j]==false && grafo[i+1][j]!=0) total+=dfs(i+1, j);
    if(j+1<m && visitados[i][j+1]==false && grafo[i][j+1]!=0) total+=dfs(i, j+1);
    
    return total;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    int t; cin >> t;
    while(t--){
        cin >> n >> m;
        
        grafo.assign(n, vector<int>(m));
        visitados.assign(n, vector<bool>(m, false));
        
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                cin >> grafo[i][j];
            }
        }
        
        int maior=0;
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(grafo[i][j]!=0 && visitados[i][j]==false){
                    maior = max(dfs(i, j), maior);
                }
            }
        }
        
        cout << maior << "\n";
    }
    
    return 0;
}