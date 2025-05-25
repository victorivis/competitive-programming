/*
https://cses.fi/problemset/task/1636
*/

#include <bits/stdc++.h>
using namespace std;

const int modulo = 1e9+7;

int main(){
    int n, k; cin >> n >> k;
    vector<int> lista(n);
    for(int i=0; i<n; i++){
        cin >> lista[i];
    }
    
    int dp[k+2]={0};
    dp[0]=1;
    
    long long total=0;
    for(int i=1; i<=n; i++){
        int coin = lista[i-1];
        
        for(int x=coin; x<=k; x++){
            dp[x] = ((long long) dp[x-coin] + dp[x])%modulo;
        }
        
        if(coin<=k){
            total = (dp[k-coin] + total)%modulo;
        }
    }
    cout << total << "\n";
 
    return 0;
}