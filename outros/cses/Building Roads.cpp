/*
https://cses.fi/problemset/task/1666/
*/

#include <bits/stdc++.h>
using namespace std;
 
vector<vector<int>> grafo;
vector<bool> vis;
 
void dfs(int n){
    vis[n]=true;
    
    for(int i=0; i<grafo[n].size(); i++){
        int atual = grafo[n][i];
        
        if(vis[atual]==false){
            dfs(atual);
        }
    }
}
 
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    int n, m; cin >> n >> m;
    
    grafo.assign(n+1, vector<int>());
    vis.assign(n+1, false);
    
    for(int i=0; i<m; i++){
        int x, y; cin >> x >> y;
        grafo[x].push_back(y);
        grafo[y].push_back(x);
    }
    
    vector<int> estradas;
    
    for(int i=1; i<=n; i++){
        if(vis[i]==false){
            dfs(i);
            
            estradas.push_back(i);
        }
    }
    
    cout << estradas.size()-1 << "\n";
    for(int i=1; i<estradas.size(); i++){
        cout << "1 " << estradas[i] << "\n";
    }
 
    return 0;
}