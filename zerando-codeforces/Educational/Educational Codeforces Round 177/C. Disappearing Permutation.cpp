/*
https://codeforces.com/contest/2086/problem/C
*/

#include <bits/stdc++.h>
using namespace std;

vector<bool> visitados;
vector<int> lista;
int total=0;

void mostrar(vector<long long>& l){
    for(long long i: l){
        cout << i << " ";
    }
    cout << "\n";
}

void processar(int num){
    if(visitados[num-1]==false){
        int temp=0;
        if(lista[num-1]!=num){
            temp=lista[num-1];
            visitados[num-1]=true;
            lista[num-1] = num;
            total++;
            
            processar(temp);
        }
        else{
            total++;
            visitados[num-1]=true;
        }
    }
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    int t; cin >> t;
    while(t--){
        int n; cin >> n;
        total=0;
        
        lista.assign(n, 0);
        vector<int> queries(n);
        visitados.assign(n, false);
        
        for(int i=0; i<n; i++){
            cin >> lista[i];
        }
        
        for(int i=0; i<n; i++){
            cin >> queries[i];
        }
        
        for(int i: queries){
            processar(i);
            
            cout << total << " ";
        }
        
        cout << "\n";
    }
    
    return 0;
}