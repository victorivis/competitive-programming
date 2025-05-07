/*
https://cses.fi/problemset/task/1158
*/

#include <bits/stdc++.h>
using namespace std;
 
int main(){
    int n, x; cin >> n >> x;
    vector<int> preco(n);
    for(int i=0; i<n; i++){
        cin >> preco[i];
    }
    
    vector<int> valor(n);
    for(int i=0; i<n; i++){
        cin >> valor[i];
    }
    
    vector<vector<int>> dp(n+1, vector<int>(x+1, 0));
    for(int i=1; i<=n; i++){
        int p = preco[i-1];
        for(int j=0; j<dp[i].size(); j++){
            dp[i][j] = dp[i-1][j];
            if(j-p>=0){
                dp[i][j] = max(dp[i][j], valor[i-1] + dp[i-1][j-p]);
            }
        }
    }
    
    cout << dp[n][x] << "\n";
    
    return 0;
}