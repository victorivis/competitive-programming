/*
https://codeforces.com/contest/2067/problem/B
*/

#include <bits/stdc++.h>
using namespace std;

const int LIM = 1e3;

int main(){
    int t; cin >> t;
    while(t--){
        int n; cin >> n;
        vector<int> lista(LIM+2, 0);
        
        for(int i=0; i<n; i++){
            int x; cin >> x;
            lista[x]++;
            
            if(x>LIM){
                exit(1);
            }
        }
        
        bool impossivel=false;
        int reserva=0;
        for(int i=1; i<=LIM+1; i++){
            if(lista[i]==0 && reserva>0){
                reserva-=2;
            }
            
            if(reserva<0){
                impossivel=true;
                break;
            }
            
            if(lista[i]>0){
                reserva += lista[i]-2;
            }
        }
        
        if((reserva%2==1) || impossivel){
            cout << "NO\n";
        }
        else{
            cout << "YES\n";
        }
    }
    
    return 0;
}