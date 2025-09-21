/* https://codeforces.com/contest/2118/problem/C */

#include <bits/stdc++.h>
using namespace std;

#define int long long

const int LIM = 64;

void recebeZeros(int num, vector<int>& zeros, int& total){
    for(int i=0; i<LIM; i++){
        if( ((num >> i)&1) == 0){
            zeros[i]++;
        }
        else{
            total++;
        }
    }
}

int32_t main(){
    int t; cin >> t;
    while(t--){
        long long n, k; cin >> n >> k;
        vector<int> lista(LIM, 0);
        int total=0;
        
        for(int i=0; i<n; i++){
            int x; cin >> x;
            recebeZeros(x, lista, total);
        }
        
        for(int i=0; i<lista.size(); i++){
            int pot = 1ll<<i;
            int possiveis = k/pot;
            int retirados = min(possiveis, lista[i]);
            
            k -= pot * retirados;
            total += retirados;
        }
        
        cout << total << "\n";
    }

    return 0;
}