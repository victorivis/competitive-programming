/* https://codeforces.com/contest/2098/problem/A */

#include <bits/stdc++.h>
using namespace std;

int main(){
    int t; cin >> t;
    
    while(t--){
        string s; cin >> s;
        int lista[10] = {0};
        
        for(char c: s){
            lista[c-'0']++;
        }
        
        for(int i=0; i<10; i++){
            int minimo = 9-i;
            
            for(int j=minimo; j<10; j++){
                if(lista[j]){
                    lista[j]--;
                    cout << j;
                    break;
                }
            }
        }
        cout << "\n";
    }
    
    return 0;
}