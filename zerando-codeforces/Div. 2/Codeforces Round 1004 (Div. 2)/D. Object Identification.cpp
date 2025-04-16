/*
https://codeforces.com/contest/2067/problem/D
*/

#include <bits/stdc++.h>
using namespace std;

int main(){
    int t; cin >> t;
    while(t--){
        int n; cin >> n;
        vector<int> lista(n);
        vector<bool> presente(n+2, false);
        int diferentes = n;
        
        int p1=-1;
        int p2=-1;
        
        for(int i=0; i<n; i++){
            cin >> lista[i];
            
            if(presente[lista[i]]==false){
                diferentes--;
            }
            
            presente[lista[i]] = true;
            
            if(lista[i]==1){
                p1 = i+1;
            }
            else if(lista[i]==n){
                p2 = i+1;
            }
        }
        
        bool impresente=false;
        if(diferentes>0){
            impresente=true;
            for(int i=1; i<=n; i++){
                if(presente[i]==false){
                    p1 = i;
                    p2 = (i%n)+1;
                    break;
                }
            }
        }
        
        cout << "? " << p1 << " " << p2 << "\n";
        cout.flush();
        int r1; cin >> r1;
        
        cout << "? " << p2 << " " << p1 << "\n";
        cout.flush();
        int r2; cin >> r2;
        
        if(r1==0 || r2==0){
            cout << "! A\n";
        }
        else if(r1+r2>n){
            cout << "! B\n";
        }
        else if(impresente){
            cout << "! B\n";
        }
        else{
            cout << "! A\n";
        }
        cout.flush();
    }
    
    return 0;
}