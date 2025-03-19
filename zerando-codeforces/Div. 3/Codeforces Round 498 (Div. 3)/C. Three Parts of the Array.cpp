/* https://codeforces.com/contest/1006/problem/C */

#include <bits/stdc++.h>
using namespace std;

#define int long long

int32_t main(){
    int n; cin >> n;
    vector<int> lista(n);
    for(int i=0; i<n; i++){
        cin >> lista[i];
    }
    
    vector<int> prefixo(n+1);
    for(int i=0; i<n; i++){
        prefixo[i+1] = lista[i] + prefixo[i];
    }
    
    int l=0, r=n;
    int maximo=0;
    while(l<=r){
        int somaL = prefixo[l] - prefixo[0];
        int somaR = prefixo[n] - prefixo[r];
        
        if(somaR < somaL){
            r--;
        }
        if(somaL < somaR){
            l++;
        }
        if(somaL == somaR){
            maximo = somaL;
            l++;
        }
    }
    
    cout << maximo << "\n";
    
    return 0;
}