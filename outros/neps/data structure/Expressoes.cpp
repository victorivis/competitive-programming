/*
https://neps.academy/br/exercise/271
*/

#include <bits/stdc++.h>
using namespace std;

char complemento(char c){
    if(c==')') return '(';
    if(c==']') return '[';
    if(c=='}') return '{';
}

int main(){
    int n; cin >> n;
    
    for(int i=0; i<n; i++){
        string s; cin >> s;
        stack<char> sequencia;
        
        for(char c: s){
            if(c=='(' || c=='[' || c=='{'){
                sequencia.push(c);
            }
            else{
                if(sequencia.empty() || sequencia.top()!=complemento(c)){
                    goto fim;
                }
                else{
                    sequencia.pop();
                }
            }
        }
        
        if(sequencia.empty()){
            cout << "S\n";
        }
        else{
            fim:
            cout << "N\n";
        }
    }

    return 0;
}