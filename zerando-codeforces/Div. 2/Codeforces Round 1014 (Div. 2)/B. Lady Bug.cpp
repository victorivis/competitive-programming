/*
https://codeforces.com/contest/2092/problem/B
*/

#include <bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    int t; cin >> t;
    
    while(t--){
        int n; cin >> n;
        
        int par=0, impar=0;
        
        for(int i=1; i<=n; i++){
            char c; cin >> c;
            if(c=='1'){
                if(i%2==1){
                    impar++;
                }
                else{
                    par++;
                }
            }
        }
        
        for(int i=1; i<=n; i++){
            char c; cin >> c;
            if(c=='1'){
                if(i%2==0){
                    impar++;
                }
                else{
                    par++;
                }
            }
        }
        
        int espacoImpar = n/2;
        int espacoPar = n/2 + n%2;
        
        if(impar<=espacoImpar && par<=espacoPar){
            cout << "YES\n";
        }
        else{
            cout << "NO\n";
        }
    }
    
    return 0;
}