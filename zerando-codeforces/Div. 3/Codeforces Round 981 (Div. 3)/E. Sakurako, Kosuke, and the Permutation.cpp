/*
https://codeforces.com/contest/2033/problem/E
*/

#include <bits/stdc++.h>
using namespace std;

int main(){
    int t; cin >> t;
    while(t--){
        int n; cin >> n;
        vector<int> lista(n);
        vector<bool> visitado(n);
        
        for(int i=0; i<n; i++){
            int x; cin >> x;
            lista[i] = x-1;
        }
        
        int total=0;
        for(int i=0; i<n; i++){
            if(visitado[i]==false){
                int proximo = lista[i];
                int cont=0;
                while(proximo!=i){
                    visitado[proximo]=true;
                    proximo = lista[proximo];
                    cont++;
                }
                visitado[i]=true;
                
                total += cont/2;
            }
        }
        cout << total << "\n";
    }

    return 0;
}