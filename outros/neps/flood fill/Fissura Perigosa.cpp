/*
https://neps.academy/br/exercise/825
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
    grafo[x][y]='*';
    
    for(int dir=0; dir<4; dir++){
        int i = x+dI[dir];
        int j = y+dJ[dir];
        
        if(isValid(i, j) && vis[i][j]==false && grafo[i][j]<=F){
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
    
    cin >> n >> F;
    m=n;
    
    vis.assign(n, vector<bool>(m, false));
    grafo.assign(n, vector<char>(m, false));
    
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            cin >> grafo[i][j];
        }
    }
    
    if(grafo[0][0]<=F){
        dfs(0, 0);
    }
    
    mostrar(grafo);
    
    return 0;
}