/*
https://judge.beecrowd.com/en/runs/code/43502823
*/

#include <bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    int n; 
    
    while(cin >> n){
        priority_queue<pair<int, string>, vector<pair<int, string>>, greater<pair<int, string>>> fila;
        
        for(int i=0; i<n; i++){
            string s; int x;
            cin >> s >> x;
            
            fila.push(pair<int, string>(x, s));
        }
        
        bool babaquice=true;
        while(fila.empty()==false){
            if(babaquice){
                babaquice=false;
            }
            else{
                cout << " ";
            }
            cout << fila.top().second;
            fila.pop();
        }
        cout << "\n";
    }
    
    return 0;
}