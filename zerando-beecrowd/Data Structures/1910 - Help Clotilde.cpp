/*
https://judge.beecrowd.com/en/problems/view/1910
*/

#include <bits/stdc++.h>
using namespace std;

const int tam = 10e5+2;
const int l=1;
const int r=1e5;

void preenche(queue<pair<int, int>>& fila, vector<bool>& visitados){
    int n = fila.front().first;
    int dist = fila.front().second+1;
    
    if(n-1 >= l && visitados[n-1]==false){
        fila.push(pair<int, int>(n-1, dist));
        visitados[n-1]=true;
    }
    
    if(n+1 <= r && visitados[n+1]==false){
        fila.push(pair<int, int>(n+1, dist));
        visitados[n+1]=true;
    }
    
    if(n%2==0 && visitados[n/2]==false){
        fila.push(pair<int, int>(n/2, dist));
        visitados[n/2]=true;
    }
    
    if(n*2 <= r && visitados[n*2]==false){
        fila.push(pair<int, int>(n*2, dist));
        visitados[n*2]=true;
    }
    
    if(n*3 <= r && visitados[n*3]==false){
        fila.push(pair<int, int>(n*3, dist));
        visitados[n*3]=true;
    }
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    int s, d, b; cin >> s >> d >> b;
    while(s+d+b!=0){
        vector<bool> visitados(tam, false);
        queue<pair<int, int>> clotilde;
        
        for(int i=0; i<b; i++){
            int x; cin >> x;
            visitados[x]=true;
        }
        
        clotilde.push(pair<int, int>(s, 0));
        visitados[s]=true;
        
        int resposta=-1;
        while(clotilde.empty()==false){
            if(clotilde.front().first == d){
                resposta = clotilde.front().second;
                goto fim;
            }
            
            preenche(clotilde, visitados);
            
            clotilde.pop();
        }
        
        fim:
        cout << resposta << "\n";
        
        cin >> s >> d >> b;
    }
    
    return 0;
}