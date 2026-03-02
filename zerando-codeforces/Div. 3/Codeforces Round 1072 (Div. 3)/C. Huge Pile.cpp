/* https://codeforces.com/contest/2184/problem/C */

#include <bits/stdc++.h>
using namespace std;

#define int long long
#define par array<int,2>

int32_t main(){
    int t; cin >> t;
    while(t--){
        int n, m; cin >> n >> m;
        
        map<int, int> d;
        
        queue<par> fila;
        d[n]=0;
        fila.push({n, 0});
        
        while(!fila.empty()){
            par atual = fila.front();
            int h = atual[1];
            fila.pop();
            
            int a = atual[0]/2;
            int b = (1+atual[0])/2;
            
            if(d.count(a) == 0){
                fila.push({a, h+1});
                d[a] = h+1;
            }
            
            if(d.count(b) == 0){
                fila.push({b, h+1});
                d[b] = h+1;
            }
        }
        
        if(d.count(m)){
            cout << d[m] << "\n";
        }
        else{
            cout << "-1\n";
        }
    }

    return 0;
}