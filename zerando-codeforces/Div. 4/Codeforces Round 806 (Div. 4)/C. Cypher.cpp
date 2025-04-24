/* https://codeforces.com/contest/1703/problem/C */

#include <bits/stdc++.h>
using namespace std;

int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    
    int t; cin >> t;
    while(t--){
        int n; cin >> n;
        vector<int> lista(n);
        
        for(int i=0; i<n; i++){
            cin >> lista[i];
        }
        
        for(int i=0; i<n; i++){
            int x; cin >> x;
            
            int total=0;
            for(int j=0; j<x; j++){
                char codigo; cin >> codigo;
                if(codigo=='D'){
                    total++;
                }
                else{
                    total--;
                }
            }
            lista[i]=(lista[i]+20+total)%10;
        }
        
        for(int i=0; i<n; i++){
            cout << lista[i] << " ";
        }
        cout << "\n";
    }

    return 0;
}