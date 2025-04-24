/* https://codeforces.com/contest/1807/problem/C */

#include <bits/stdc++.h>
using namespace std;

int main(){
    int t; cin >>t;
    while(t--){
        int n; cin >> n;
        string s; cin >> s;
        
        map<char, int> letras;
        for(int i=0; i<n; i++){
            char atual = s[i];
            if(letras.count(atual)==0){
                letras[atual]=i%2;
            }
            else if(i%2!=letras[atual]){
                goto fim;
            }
        }
        
        cout << "YES\n";
        if(false){
            fim:
            cout << "NO\n";
        }
    }
    
    return 0;
}