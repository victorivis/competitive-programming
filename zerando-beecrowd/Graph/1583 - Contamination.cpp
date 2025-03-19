/*
https://judge.beecrowd.com/en/problems/view/1583
*/

#include <bits/stdc++.h>
using namespace std;

int n, m;
char F;

int total=0;

int dI[] = {-1, 0, 1, 0};
int dJ[] = {0, -1, 0, 1};

vector<vector<bool>> vis;
vector<vector<char>> grafo;

bool isValid(int i, int j){
    if(i<0 || i>=n || j<0 || j>=m){
        return false;
    }
    return true;
}

void dfs(int x, int y){
    vis[x][y]=true;
    grafo[x][y]='T';
    
    for(int dir=0; dir<4; dir++){
        int i = x+dI[dir];
        int j = y+dJ[dir];
        
        if(isValid(i, j) && vis[i][j]==false && grafo[i][j]=='A'){
            dfs(i, j);
        }
    }
}

void mostrar(vector<vector<char>>& matriz){
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            cout << matriz[i][j];
        }
        cout << "\n";
    }
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> n >> m;
    
    bool first=true;
    while(n!=0 && m!=0){
        vis.assign(n, vector<bool>(m, false));
        grafo.assign(n, vector<char>(m, false));
        
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                cin >> grafo[i][j];
            }
        }
        
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(vis[i][j]==false && grafo[i][j]=='T'){
                    dfs(i, j);
                }
            }
        }
        
        mostrar(grafo);
        cout << "\n";
        
        cin >> n >> m;
    }
    
    return 0;
}