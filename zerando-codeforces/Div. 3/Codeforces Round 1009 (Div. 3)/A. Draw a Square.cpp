/*
https://codeforces.com/contest/2074/problem/A
*/

#include <bits/stdc++.h>
using namespace std;

const int tam = 4;

int main(){
    int t; cin >> t;
    while(t--){
        vector<int> lista(tam);
        
        for(int i=0; i<tam; i++){
            cin >> lista[i];
        }
        
        bool resultado=true;
        for(int i=1; i<tam; i++){
            resultado = resultado && (lista[i]==lista[0]);
        }
        
        if(resultado){
            cout << "Yes\n";
        }
        else{
            cout << "No\n";
        }
    }

    return 0;
}