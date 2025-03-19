/*
https://cses.fi/problemset/task/1193
*/

#include <bits/stdc++.h>
using namespace std;
 
struct par{
    int x;
    int y;
    char c;
};
 
int n, m;
 
vector<vector<char>> matriz;
vector<vector<bool>> vis;
vector<vector<par>> anterior;
 
void bfs(queue<par>& fila){
    par pos = fila.front();
    int x = pos.x;
    int y = pos.y;
    
    if(x+1<n && matriz[x+1][y]!='#' && vis[x+1][y]==false){
        pos.c='D';
        anterior[x+1][y] = pos; 
        fila.push({x+1, y, 'D'});
        vis[x+1][y]=true;
    }
    
    if(x-1>=0 && matriz[x-1][y]!='#' && vis[x-1][y]==false){
        pos.c='U';
        anterior[x-1][y] = pos; 
        fila.push({x-1, y, 'U'});
        vis[x-1][y]=true;
    }
    
    if(y+1<m && matriz[x][y+1]!='#' && vis[x][y+1]==false){
        pos.c='R';
        anterior[x][y+1] = pos; 
        fila.push({x, y+1, 'R'});
        vis[x][y+1]=true;
    }
    
    if(y-1>=0 && matriz[x][y-1]!='#' && vis[x][y-1]==false){
        pos.c='L';
        anterior[x][y-1] = pos; 
        fila.push({x, y-1, 'L'});
        vis[x][y-1]=true;
    }
}
 
void mostrar(par& p){
    cout << "{" << p.x << ", " << p.y << ", " << p.c << "} ";
}
 
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> n >> m;
    
    matriz.assign(n, vector<char>(m));
    vis.assign(n, vector<bool>(m, false));
    anterior.assign(n, vector<par>(m, {-1, -1, 1}));
    
    par inicio;
    int dx, dy;
    
    
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            cin >> matriz[i][j];
            
            if(matriz[i][j]=='A'){
                inicio = {i, j, 1};
            }
            else if(matriz[i][j]=='B'){
                dx = i;
                dy = j;
            }
        }
    }
    
    queue<par> fila;
    fila.push(inicio);
    vis[inicio.x][inicio.y]=true;
    
    while(fila.empty()==false){
        if(fila.front().x==dx && fila.front().y==dy){
            break;
        }
        
        bfs(fila);
        fila.pop();
    }
    
    if(vis[dx][dy]==false){
        cout << "NO\n";
    }
    else{
        stack<char> saida;
        int total=0;
        
        par atual=anterior[dx][dy];
        
        while(atual.c != 1){            
            saida.push(atual.c);
            total++;
            
            atual = anterior[atual.x][atual.y];
        }
        
        cout << "YES\n";
        cout << total << "\n";
        while(saida.empty()==false){
            cout << saida.top();
            saida.pop();
        }
        cout << "\n";
    }
 
    return 0;
}