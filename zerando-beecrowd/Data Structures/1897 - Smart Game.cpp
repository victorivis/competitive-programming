/*
https://judge.beecrowd.com/en/problems/view/1897
*/

#include <bits/stdc++.h>
using namespace std;

int maximo = (1<<30)/3;

void preenche(queue<pair<int, int>>& fila, map<int, bool>& visitados){
    int n = fila.front().first;
    int dist = fila.front().second+1;
    
    if(n >= maximo || n <= -maximo) return;
    
    if(visitados[n*2]==false){
        fila.push(pair<int, int>(n*2, dist));
        visitados[n*2]=true;
    }
    
    if(visitados[n*3]==false){
        fila.push(pair<int, int>(n*3, dist));
        visitados[n*3]=true;
    }
    
    if(visitados[n/2]==false){
        fila.push(pair<int, int>(n/2, dist));
        visitados[n/2]=true;
    }
    
    if(visitados[n/3]==false){
        fila.push(pair<int, int>(n/3, dist));
        visitados[n/3]=true;
    }
    
    if(visitados[n-7]==false){
        fila.push(pair<int, int>(n-7, dist));
        visitados[n-7]=true;
    }
    
    if(visitados[n+7]==false){
        fila.push(pair<int, int>(n+7, dist));
        visitados[n+7]=true;
    }
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    int s, d; cin >> s >> d;
    
    map<int, bool> visitados;
    queue<pair<int, int>> game;
    
    game.push(pair<int, int>(s, 0));
    visitados[s]=true;
    
    while(game.empty()==false && game.front().first!=d){
        preenche(game, visitados);
        
        game.pop();
    }
    cout << game.front().second << "\n";
    
    return 0;
}