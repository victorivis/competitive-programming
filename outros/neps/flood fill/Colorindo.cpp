/*
https://neps.academy/br/exercise/535
*/

#include <bits/stdc++.h>
using namespace std;

int n, m;

int total=0;

int dI[] = {-1, 0, 1, 0, 1, -1, 1, -1};
int dJ[] = {0, -1, 0, 1, 1, -1, -1, 1};

vector<vector<bool>> vis;

bool isValid(int i, int j){
    if(i<0 || i>=n || j<0 || j>=m){
        return false;
    }
    return true;
}

void dfs(int x, int y){
    vis[x][y]=true;
    total++;
    
    for(int dir=0; dir<8; dir++){
        int i = x+dI[dir];
        int j = y+dJ[dir];
        
        if(isValid(i, j) && vis[i][j]==false){
            dfs(i, j);
        }
    }
}

void mostrar(vector<vector<int>>& matriz){
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
    
    int x, y, k;
    cin >> n >> m >> x >> y >> k;
    
    x--;
    y--;
    
    vis.assign(n, vector<bool>(m, false));
    
    for(int i=0; i<k; i++){
        int a, b; cin >> a >> b;
        vis[a-1][b-1]=true;
    }
    
    dfs(x, y);
    cout << total << "\n";
    
    return 0;
}