/*
https://judge.beecrowd.com/en/problems/view/2929
*/

#include <bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    int n; cin >> n;
    
    stack<int> pilha;
    priority_queue<int, vector<int>, greater<int>> controle;
    priority_queue<int, vector<int>, greater<int>> deletados;
    
    for(int i=0; i<n; i++){
        string s; cin >> s;
        
        if(s=="PUSH"){
            int x; cin >> x;
            pilha.push(x);
            controle.push(x);
        }
        else{
            if(pilha.empty()){
                cout << "EMPTY\n";
            }
            else if(s=="POP"){
                deletados.push(pilha.top());
                
                while(deletados.empty()==false && deletados.top()==controle.top()){
                    deletados.pop();
                    controle.pop();
                }
                
                pilha.pop();
            }
            else{
                cout << controle.top() << "\n";
            }
        }
    }
    
    return 0;
}