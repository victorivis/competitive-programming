/* https://codeforces.com/contest/2109/problem/A */

#include <bits/stdc++.h>
using namespace std;

int main(){
    int t; cin >> t;
    
    while(t--){
        bool temZero=false;
        int n; cin >> n;
        bool liar=false;
        
        vector<int> respostas(n);
        
        cin >> respostas[0];
        if(respostas[0]==0){
            temZero=true;
        }
        
        for(int i=1; i<n; i++){
            cin >> respostas[i];
            if(respostas[i]==0){
                temZero=true;
            }
            
            if(respostas[i-1]==respostas[i] && respostas[i]==0){
                liar=true;
            }
        }
        
        cout << ((liar || temZero==false) ? "YES\n": "NO\n");
    }

    return 0;
}