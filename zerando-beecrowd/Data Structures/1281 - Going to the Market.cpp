/*
https://judge.beecrowd.com/en/runs/code/43497837
*/

#include <bits/stdc++.h>
using namespace std;

const int tam = 1e6+3;

int main() {
    int t; cin >> t;
    while(t--){
        int n; cin >> n;
        map<string, float> d;
        
        for(int i=0; i<n; i++){
            string s; float f;
            cin >> s >> f;
            d[s]=f;
        }
        
        int q; cin >> q;
        float total=0;
        for(int i=0; i<q; i++){
            string s; int m;
            cin >> s >> m;
            
            total += d[s]*m;
        }
        
        cout << "R$ ";
        printf("%.2f", total);
        cout << "\n";
    }
    
    return 0;
}