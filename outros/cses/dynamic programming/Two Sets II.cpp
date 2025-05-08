/*
https://cses.fi/problemset/task/1093
*/

#include <bits/stdc++.h>
using namespace std;
 
const int modulo = 1e9+7;
 
int main(){
    int n; cin >> n;
    int total=n*(n+1)/2;
    
    if(total%2==1){
        cout << "0\n";
        return 0;
    }
    
    int limite = total/2;
    
    vector<vector<int>> dp(n+1, vector<int>(limite+1, 0));
    dp[0][0]=1;
    
    for(int i=1; i<=n; i++){
        int moeda = i;
        for(int j=0; j<=limite-moeda; j++){
            if(dp[i-1][j]>0){
                dp[i][j] = ((long long) dp[i][j] + dp[i-1][j])%modulo;
                dp[i][j+moeda] = ((long long) dp[i-1][j] + dp[i][j+moeda])%modulo;
            }
        }
    }
    
    cout << dp[n][limite] << "\n";
    
    return 0;
}
