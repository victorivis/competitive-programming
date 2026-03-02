/* https://codeforces.com/contest/2184/problem/D */

#include <bits/stdc++.h>
using namespace std;

#define int long long

const int mod = 1e9+7;
const int LG = __lg(mod)+1;
const int LIM = 1e6;

int fat[LIM];

void init(){
    fat[0]=1;
    for(int i=1; i<LIM; i++){
        fat[i] = i*fat[i-1]%mod;
    }
}

int binpow(int a, int b, int m){
    if(b==0) return 1;
    int part = binpow(a, b/2, m);
    int result = part*part%m;
    if(b&1) result *= a;
    return result%m;
}

int inv(int num){
    return binpow(num, mod-2, mod);
}

int perm(int a, int b){
    int num = fat[a];
    int den = fat[b]*fat[a-b]%mod;
    return num * inv(den) % mod;
}

int func(int num){
    return __lg(num) + __builtin_popcount(num);
}

signed main(){
    init();    
    vector<vector<int>> somas(LG+1, vector<int>(LG+1, 0));
    
    for(int i=0; i<LG; i++){
        for(int j=i; ~j; j--){
            somas[i][j] = somas[i][j+1] + perm(i,j);
        }
    }
    
    int t; cin >> t;
    while(t--){
        int n, k; cin >> n >> k;
        int pot = __lg(n)-1;
        int total = 0;
        for(int i=pot; ~i; i--){
            int pos = max(0ll, k-i);

            if(pos<=i){
                total += somas[i][pos];
            }
        }
        if(func(n) > k) total++;
        cout << total << "\n";
    }
    
    return 0;
}