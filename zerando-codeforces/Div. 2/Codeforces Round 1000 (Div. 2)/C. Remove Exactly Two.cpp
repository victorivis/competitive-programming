#include <bits/stdc++.h>
using namespace std;

bool estaNaLista(vector<int>& lista, int n){
    for(int i: lista){
        if(i==n){
            return true;
        }
    }
    return false;
}

struct Par{
    int val;
    int id;
};

bool ordenar(Par& a, Par& b){
    return a.val < b.val;
}

int main(){
    int t; cin >> t;
    while(t--){
        int n; cin >> n;
        vector<vector<int>> matriz(n+1);
        
        for(int i=0; i<n-1; i++){
            int x, y; cin >> x >> y;
            matriz[y].push_back(x);
            matriz[x].push_back(y);
        }
        
        vector<Par> lista(n+1);
        for(int i=1; i<=n; i++){
            lista[i] = {static_cast<int>(matriz[i].size()), i};
        }
        
        sort(lista.begin(), lista.end(), ordenar);
        
        int penultimo = lista[n-1].val;
        int pos = n-2;
        int quantidade=1;
        while(pos > 0 && lista[pos].val==penultimo){
            quantidade++;
            pos--;
        }
        
        int total;

        if(penultimo==lista[n].val && quantidade>=2){
            total = lista[n].val + penultimo;
        }
        else{
            bool NaoVisinhos=false;
            for(int i=n-1; i>pos; i--){
                if(estaNaLista(matriz[lista[i].id], lista[n].id)==false){
                    NaoVisinhos=true;
                    break;
                }
            }
            
            total=lista[n].val+penultimo;
            if(NaoVisinhos==false){
                total--;
            }
        }
        
        cout << total-1 << "\n";
    }
    
    return 0;
}