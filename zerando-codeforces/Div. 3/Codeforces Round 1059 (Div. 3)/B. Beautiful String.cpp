/* https://codeforces.com/contest/2162/problem/B */

#include <bits/stdc++.h>
using namespace std;

int main(){
    int t; cin >> t;
    while(t--){
        int n; cin >> n;
        string s; cin >> s;
        
        int total=0;
        queue<int> fila;
        
        for(int i=0; i<s.size(); i++){
            if(s[i]=='0'){
                total++;
                fila.push(i+1);
            }
        }
        
        cout << total << "\n";
        while(!fila.empty()){
            cout << fila.front() << " ";
            fila.pop();
        }
        cout << "\n";
    }
    
    return 0;
}