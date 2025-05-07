/*
https://cses.fi/problemset/task/1635
*/

#include <bits/stdc++.h>
using namespace std;
 
const int modulo = 1e9+7;
vector<int> dp(1e6+5, 0);
 
struct par{
    int x;
    int y;
};
 
int main(){
    int n, k; cin >> n >> k;
    vector<int> coins(n);
    for(int i=0; i<n; i++){
        cin >> coins[i];
    }
    
    queue<int> proximo;
    dp[0]=1;
    proximo.push(0);
    
    for(int atual=1; atual<=k; atual++){
        long long total=0;
        for(int j=0; j<coins.size(); j++){
            if(atual - coins[j] >= 0){
                total = (total + dp[atual - coins[j]]) % modulo;
            }
        }
        dp[atual] = total;
    }
    
    cout << dp[k] << "\n";
    
    return 0;
}