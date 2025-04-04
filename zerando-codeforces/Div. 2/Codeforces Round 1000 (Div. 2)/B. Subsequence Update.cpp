/*
https://codeforces.com/contest/2063/problem/B
*/

#include <bits/stdc++.h>
using namespace std;

void mostrar(vector<int>& l){
    for(int i: l){
        cout << i << " ";
    }
    cout << "\n";
}

int main(){
    int t; cin >> t;
    while(t--){
        int n, l, r; cin >> n >> l >> r;
        vector<int> listaL(n);
        vector<int> listaR(n);
        
        l--; r;
        
        for(int i=0; i<n; i++){
            int x; cin >> x;
            listaL[i] = x;
            listaR[i] = x;
        }
        
        sort(listaR.begin()+l, listaR.end());
        sort(listaL.begin(), listaL.begin()+r, greater<int>());
        
        long long totL=0;
        long long totR=0;
        
        for(int i=l; i<r; i++){
            totL += listaL[i];
            totR += listaR[i];
        }
        
        cout << min(totL, totR) << "\n";
    }

    return 0;
}