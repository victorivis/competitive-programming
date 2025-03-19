/*
https://atcoder.jp/contests/abc216/tasks/abc216_d
*/

#include <bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    int N, M; cin >> N >> M;
    
    vector<stack<int>> container(M);
    
    for(int i=0; i<M; i++){
        int m; cin >> m;
        
        for(int j=0; j<m; j++){
            int x; cin >> x;
            
            container[i].push(x);
        }
    }
    
    vector<int> retirados(N+1, 0);
    vector<int> posicao(N+1, -1);
    
    queue<int> visitar;
    for(int i=0; i<M; i++){
        visitar.push(i);
    }
    
    int total=0;
    
    while(visitar.empty()==false){
        total++;
        int pilha = visitar.front();
        
        int atual = container[pilha].top();
        if(retirados[atual]==0){
            posicao[atual] = pilha;
        }
        else{
            if(posicao[atual]==-1){
                cout << "Oh, ceus!\n";
                goto erro;
            }
            
            int retirar1 = posicao[atual];
            int retirar2 = pilha;
            
            container[retirar1].pop();
            if(container[retirar1].empty()==false){
                visitar.push(retirar1);
            }
            
            container[retirar2].pop();
            if(container[retirar2].empty()==false){
                visitar.push(retirar2);
            }
        }
        retirados[atual]++;
        
        visitar.pop();
    }
    
    erro:
    if(total == 2*N){
        cout << "Yes\n";
    }
    else{
        cout << "No\n";
    }
    
    return 0;
}