/*
https://cses.fi/problemset/task/1638
*/

#include <bits/stdc++.h>
using namespace std;
 
const int modulo = 1e9+7;
 
int main(){
    int n; cin >> n;
    vector<string> matriz(n);
    vector<vector<int>> dp(n+1, vector<int>(n+1, 0));
    
    for(int i=0; i<n; i++){
        cin >> matriz[i];
    }
    
    for(int i=1; i<=n; i++){
        for(int j=1; j<=n; j++){
            if(i==1 && j==1){
                dp[i][j] = (matriz[i-1][j-1]!='*' ? 1 : 0);
                continue;
            }
            
            dp[i][j] = ((long long) dp[i][j-1] + dp[i-1][j])%modulo;
            
            if(matriz[i-1][j-1]=='*'){
                dp[i][j]=0;
            }
        }
    }
    
    cout << dp[n][n] << "\n";
    
    return 0;
}
