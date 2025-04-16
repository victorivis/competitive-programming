/*
https://codeforces.com/contest/2092/problem/A
*/

#include <bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    int t; cin >> t;
    
    while(t--){
        int n; cin >> n;
        
        int menor=INT_MAX;
        int maior=0;
        
        for(int i=0; i<n; i++){
            int x; cin >> x;
            menor = min(menor, x);
            maior = max(maior, x);
        }
        
        cout << maior - menor << "\n";
    }
    
    return 0;
}