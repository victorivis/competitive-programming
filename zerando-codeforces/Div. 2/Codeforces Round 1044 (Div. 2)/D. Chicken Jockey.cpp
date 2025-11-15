/* https://codeforces.com/contest/2133/problem/D */

#include <bits/stdc++.h>
using namespace std;

#define int long long

vector<int> lista;
vector<int> dp;

int32_t main(){
    int t; cin >> t;
    while(t--){
        int n; cin >> n;
        lista.assign(n+1, 0);
        dp.assign(n+1, 0);
        
        for(int i=0; i<n; i++){
            cin >> lista[i];
        }
        
        dp[1]=lista[0];
        
        for(int i=2; i<=n; i++){
            int a = dp[i-1] + lista[i-1]-1;
            int b = dp[i-2] + lista[i-2] + max(lista[i-1] - i + 1, 0ll);
            dp[i]=min(a, b);
        }
        
        cout << dp[n] << "\n";
    }

    return 0;
}