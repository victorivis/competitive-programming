/*
https://judge.beecrowd.com/en/runs/code/43506188
*/

#include <bits/stdc++.h>
using namespace std;

#define int long long

bool comp(pair<int, int> a, pair<int, int> b){
    if(a.first != b.first) return a.first > b.first;
    return a.second < b.second;
}

int32_t main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    int t; cin >> t; 
    
    while(t--){
        int n, k; cin >> n >> k;
        
        vector<pair<int, int>> fila;
        for(int i=0; i<n; i++){
            int id, w, h, l; cin >> id >> w >> h >> l;
            pair<int, int> par(w*h*l, id);
            fila.push_back(par);
        }
        
        sort(fila.begin(), fila.end(), comp);
        
        vector<int> megaBabaquicePorNada(k);
        for(int i=0; i<k; i++){
            megaBabaquicePorNada[i]=fila[i].second;;
        }
        sort(megaBabaquicePorNada.begin(), megaBabaquicePorNada.end());
        
        bool babaquice=true;
        for(int i=0; i<k; i++){
            if(babaquice){
                babaquice=false;
            }
            else{
                cout << " ";
            }
            cout << megaBabaquicePorNada[i];
        }
        cout << "\n";
    }
    
    return 0;
}