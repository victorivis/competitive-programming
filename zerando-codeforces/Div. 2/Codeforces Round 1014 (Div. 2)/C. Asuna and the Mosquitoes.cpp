/*
https://codeforces.com/contest/2092/problem/C
*/

#include <bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    int t; cin >> t;
    
    while(t--){
        int n; cin >> n;
        vector<int> lista(n);
        
        int maior=0;
        int posMaior=-1;
        
        int par=0;
        int impar=0;
        
        for(int i=0; i<n; i++){
            cin >> lista[i];
            
            if(maior < lista[i]){
                maior = lista[i];
                posMaior = i;
            }
            
            if(lista[i]%2==0){
                par++;
            }
            else{
                impar++;
            }
        }
        
        if(par>0 && impar>0){
            long long total=maior;
            
            if(maior%2==0){
                total++;
            }
            
            for(int i=0; i<n; i++){
                if(i==posMaior) continue;
                
                int adicionar = lista[i]-lista[i]%2;
                total += adicionar;
            }
            
            cout << total << "\n";
        }
        else{
            cout << maior << "\n";
        }
    }
    
    return 0;
}