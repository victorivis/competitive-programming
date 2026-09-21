// https://codeforces.com/contest/2194/problem/D

#include <bits/stdc++.h>
using namespace std;

#define par array<int,2>
#define ll long long

int main(){
    int t; cin >> t;
    while(t--){
        int n, m; cin >> n >> m;
        int li[n][m];
        
        ll total=0;
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                cin >> li[i][j];
                total += li[i][j];
            }
        }
        
        par last;
        int cont=0;
        int obj = (total>>1) + (total&1);
        for(int i=n-1; i>=0; i--){
            for(int j=0; j<m; j++){
                cont += li[i][j];
                
                if(cont == obj){
                    last = {i, j};
                    goto fora;
                }
            }
        }
        fora:
        
        par begin = {0,0};
        par end = {n, m};
        
        ll maximo = obj*(total/2);
        
        cout << maximo << "\n";
        
        auto dist = [&](par& a, par& b){
            int dx = b[1]-a[1];
            int dy = b[0]-a[0];
            
            for(int i=0; i<dy; i++){
                cout << "D";
            }
            for(int i=0; i<dx; i++){
                cout << "R";
            }
            
            assert(dx>=0 && dy>=0);
        };
        
        par supLast = {last[0], last[1]+1};
        dist(begin, supLast);
        
        par supEnd = {last[0]+1, m};
        dist(supLast, supEnd);
        
        dist(supEnd, end);
        
        cout << "\n";
    }
    
    return 0;
}