/*
https://judge.beecrowd.com/en/problems/view/2851
*/

#include <bits/stdc++.h>
using namespace std;

void mostrar(deque<int>& lista){
    for(int i: lista){
        cout << i << " ";
    }
    cout << "\n";
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    int n; cin >> n;
    vector<int> lista(n);
    for(int i=0; i<n; i++){
        cin >> lista[i];
    }
    
    deque<int> maior = {lista[n-1]};
    deque<int> id = {n-1};
    
    stack<int> resposta;
    resposta.push(-1);
    
    for(int i=n-2; i>=0; i--){
        
        int atual = lista[i];
        
        auto it = upper_bound(maior.begin(), maior.end(), atual);
        int pos = (it - maior.begin());
        
        if(it!=maior.end()){
            resposta.push(*it);
        }
        else{
            resposta.push(-1);
        }
        
        for(int j=0; j<pos; j++){
            maior.pop_front();
            id.pop_front();
        }
        maior.push_front(atual);
        id.push_front(i);
    }
    
    bool babaquice=true;
    while(resposta.empty()==false){
        if(babaquice){
            babaquice=false;
        }
        else{
            cout << " ";
        }
        
        if(resposta.top()!=-1){
            cout << resposta.top();
        }
        else{
            cout << "*";
        }
        resposta.pop();
    }
    cout << "\n";
    
    return 0;
}