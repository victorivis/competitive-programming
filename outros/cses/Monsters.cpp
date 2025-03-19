/*
https://cses.fi/problemset/task/1194/
*/

#include <bits/stdc++.h>
using namespace std;
 
int n, m;
 
int dI[] = {-1, 0, 1, 0};
int dJ[] = {0, -1, 0, 1};
char moves[] = {'U', 'L', 'D', 'R'};
 
struct par{
    int x;
    int y;
    int d;
};
 
vector<vector<bool>> visM;
vector<vector<bool>> visP;
vector<vector<char>> prevMove;
vector<vector<par>> previous;
 
bool isValid(int i, int j){
    if(i<0 || j<0 || i>=n || j>=m){
        return false;
    }
    return true;
}
 
void bfs(queue<par>& fila, vector<vector<bool>>& vis, bool p=false){
    par atual = fila.front();
    fila.pop();
    int i = atual.x;
    int j = atual.y;
    int d = atual.d+1;
    
    for(int dir=0; dir<4; dir++){
        int x = i+dI[dir];
        int y = j+dJ[dir];
        
        if(isValid(x,y) && vis[x][y]==false){
            fila.push({x,y,d});
            vis[x][y]=true;
            if(p==false) visP[x][y]=true;
            else{
                previous[x][y] = atual;
                prevMove[x][y] = moves[dir];
            }
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
 
void mostrar(par& p){
    cout << "(" << p.x << "," << p.y << "," << p.d << ") ";
}
 
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> n >> m;
    
    previous.assign(n, vector<par>(m, {-1, -1, -1}));
    visM.assign(n, vector<bool>(m, false));
    visP.assign(n, vector<bool>(m, false));
    prevMove.assign(n, vector<char>(m, '!'));
    
    queue<par> monster;
    queue<par> player;
    
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            char c; cin >> c;
            
            if(c=='#'){
                visM[i][j]=true;
                visP[i][j]=true;
            }
            else if(c=='M'){
                visM[i][j]=true;
                visP[i][j]=true;
                monster.push({i, j, 0});
            }
            else if(c=='A'){
                visP[i][j]=true;
                player.push({i, j, 0});
            }
        }
    }
    
    int pi = player.front().x;
    int pj = player.front().y;
    
    int cont=1;
    while(player.empty()==false){
        
        while(monster.empty()==false && monster.front().d<cont){
            bfs(monster, visM, false);
        }
        while(player.empty()==false && player.front().d<cont){
            bfs(player, visP, true);
        }
        cont++;
    }
    
    par ultimo = {-1, -1, -1};
    if(pi==0 || pi==n-1 || pj==0 || pj==m-1){
        goto sim;
    }
    
    for(int i=0; i<n; i++){
        if(previous[i][0].x!=-1){
            ultimo={i,0,0};
            goto fim;
        }
        if(previous[i][m-1].x!=-1){
            ultimo={i,m-1,0};
            goto fim;
        }
    }
    
    for(int j=0; j<m; j++){
        if(previous[0][j].x!=-1){
            ultimo={0,j,0};
            goto fim;
        }
        if(previous[n-1][j].x!=-1){
            ultimo={n-1,j,0};
            goto fim;
        }
    }
    
    fim:
    
    if(ultimo.x==-1){
        cout << "NO\n";
    }
    else{
        sim:
        cout << "YES\n";
        
        stack<char> saida;
        
        int total=-1;
        while(ultimo.x!=-1){
            total++;
            saida.push(prevMove[ultimo.x][ultimo.y]);
            ultimo = previous[ultimo.x][ultimo.y];
        }
        
        cout << max(total, 0) << "\n";
        
        if(saida.empty()==false){
            saida.pop();
            while(saida.empty()==false){
                cout << saida.top();
                saida.pop();
            }
            cout << "\n";
        }
    }
    
    return 0;
}