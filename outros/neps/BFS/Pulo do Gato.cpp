/*
https://neps.academy/br/exercise/368
*/

#include <bits/stdc++.h>
using namespace std;

int l, c;

struct par{
    int x;
    int y;
    int w;
};

vector<vector<bool>> visitados;
vector<vector<bool>> matriz;

void bfs(par& pos, queue<par>& fila){
    int x = pos.x;
    int y = pos.y;
    int w = pos.w + 1;
    
    for(int i=-2; i<=2; i++){
        for(int j=-2; j<=2; j++){
            if(x+i>=0 && x+i<l && y+j>=0 && y+j<c && visitados[x+i][y+j]==false && matriz[x+i][y+j]==true){
                fila.push({x+i, y+j, w});
                visitados[x+i][y+j]=true;
            }
        }
    }
}

int main(){
    cin >> l >> c;
    matriz.assign(l, vector<bool>(c));
    
    for(int i=0; i<l; i++){
        for(int j=0; j<c; j++){
            int x; cin >> x;
            matriz[i][j] = x;
        }
    }
    
    visitados.assign(l, vector<bool>(c, false));
    
    queue<par> fila;
    fila.push({0, 0, 0});
    visitados[0][0] = true;
    
    int resposta = -1;
    while(fila.empty()==false){
        par atual = fila.front();
        
        if(atual.x == l-1 && atual.y == c-1){            
            resposta=atual.w;
            break;
        }
        
        bfs(atual, fila);
        
        fila.pop();
    }
    
    cout << resposta << "\n";
    
    return 0;
}