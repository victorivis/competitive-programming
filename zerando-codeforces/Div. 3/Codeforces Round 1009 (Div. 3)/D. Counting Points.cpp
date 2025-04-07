/*
https://codeforces.com/contest/2074/problem/D
*/

#include <bits/stdc++.h>
using namespace std;

#define int long long

int32_t main(){
    int t; cin >> t;
    while(t--){
        int n, m; cin >> n >> m;
        
        vector<int> lista(n);
        
        for(int i=0; i<n; i++){
            cin >> lista[i];
        }
        
        map<int, long long> d;
        
        for(int i=0; i<n; i++){
            int r; cin >> r;
            
            for(int j=-r; j<=r; j++){
                long long intervalo = sqrt(r*r - j*j);
                d[lista[i]+j] = max(intervalo, d[lista[i]+j]);
            }
        }
        
        long long total=0;
        for(auto& par: d){
            total+= 2*par.second+1;
        }
        
        cout << total << "\n";
    }
    
    return 0;
}