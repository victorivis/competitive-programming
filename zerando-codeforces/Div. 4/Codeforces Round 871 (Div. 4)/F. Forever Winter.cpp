/* https://codeforces.com/contest/1829/problem/F */

#include <bits/stdc++.h>
using namespace std;

int n, m;
vector<vector<int>> grafo;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    int t; cin >> t;
    while(t--){
        cin >> n >> m;
        
        grafo.assign(n+1, vector<int>());
        
        map<int, int> d;
        
        for(int i=0; i<m; i++){
            int x, y; cin >> x >> y;
            grafo[x].push_back(y);
            grafo[y].push_back(x);
        }
        
        int maior=0;
        int menor=INT_MAX;
        
        int x, y;
        for(int i=1; i<=n; i++){
            int tam = grafo[i].size();
            if(tam==1){
                int proximo = grafo[i][0];
                x = grafo[proximo].size();
                
                for(int i=0; i<x; i++){
                    int atual = grafo[proximo][i];
                    if(grafo[atual].size()!=1){
                        y = grafo[atual].size();
                    }
                }
            }
        }
        
        cout << y << " " << x-1 << "\n";
    }
    
    return 0;
}