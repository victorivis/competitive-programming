/* https://codeforces.com/contest/2061/problem/C */

#include <bits/stdc++.h>
using namespace std;

#define int long long
#define par array<int,2>

const int mod = 998244353;

int32_t main(){
    int t; cin >> t;
    while(t--){
        int n; cin >> n;
        vector<int> li(n+1, 0);
        for(int i=1; i<=n; i++){
            cin >> li[i];
        }
        
        vector<vector<par>> dp(2, vector<par>(n+1));
        dp[0][0] = {1, 0};
        dp[1][0] = {0, 0};
        
        for(int i=1; i<=n; i++){
            if(dp[0][i-1][1] == li[i]){
                dp[0][i][0] += dp[0][i-1][0];
                dp[0][i][1] = dp[0][i-1][1];
            }
            
            dp[1][i][0] += dp[0][i-1][0];
            dp[1][i][1] = dp[0][i-1][1]+1;
            
            if(dp[1][i-1][1] == li[i]){
                dp[0][i][0] += dp[1][i-1][0];
                dp[0][i][1] = dp[1][i-1][1];
            }
            
            dp[0][i][0] = (dp[0][i][0])%mod;
            dp[1][i][0] = (dp[1][i][0])%mod;
        }
        
        cout << (dp[0][n][0] + dp[1][n][0])%mod << "\n";
    }

    return 0;
}