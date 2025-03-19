/*
https://judge.beecrowd.com/en/problems/view/1069
*/

#include <bits/stdc++.h>
using namespace std;

bool comp(pair<int, int> a, pair<int, int> b){
    if(a.first != b.first) return a.first > b.first;
    return a.second < b.second;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    int t; cin >> t; 
    
    while(t--){
        string s; cin >> s;
        int cont=0;
        
        stack<char> pilha;
        for(int i=0; i<s.size(); i++){
            if(s[i]=='<') pilha.push('<');
            else if(s[i]=='>'){
                if(pilha.empty()==false){
                    pilha.pop();
                    cont++;
                }
            }
        }
        
        cout << cont << "\n";
    }
    
    return 0;
}