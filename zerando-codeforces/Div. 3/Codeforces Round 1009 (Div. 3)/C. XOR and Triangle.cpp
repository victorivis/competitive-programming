/*
https://codeforces.com/contest/2074/problem/C
*/

#include <bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int t; cin >> t;
    while(t--){
        long long n; cin >> n;
        int backupN = n;
        
        int cont=0;
        int ultimoZero=-1;
        int primeiroUm=-1;
        int quantUm=0;
        while(n>0){            
            if((n&1)==0){
                ultimoZero=cont;
            }
            else{
                if(quantUm==0){
                    primeiroUm=cont;
                }
                quantUm++;
            }
            
            n/=2;
            cont++;
        }
        
        if(ultimoZero==-1 || quantUm<2){
            cout << "-1\n";
        }
        else{
            int todosUm = (1<<cont)-1;
            int xorMaior = (todosUm ^ backupN) + (1<<(primeiroUm));
            
            cout << xorMaior << "\n";
        }
    }

    return 0;
}