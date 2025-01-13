/* https://codeforces.com/contest/1881/problem/E */

#include <bits/stdc++.h>
using namespace std;
 
int main(){
    int t; cin>>t;
    while(t--){
        int n; cin >> n;
        vector<int> lista(n);
        for(int i=0; i<n; i++){
            cin >> lista[i];
        }
        
        vector<int> dp(n+1, INT_MAX);
        dp[n] = 0;
        
        for(int i=n-1; i>=0; i--){
            if(i+lista[i]+1 < dp.size()){
                dp[i] = dp[i+lista[i]+1];
            }
            
            dp[i] = min(dp[i], dp[i+1] + 1);
        }
        
        int total=INT_MAX;
        for(int i=0; i<=n; i++){
            total = min(total, i+dp[i]);
        }
        cout << total << "\n";
    }
 
    return 0;
}