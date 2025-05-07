/*
https://cses.fi/problemset/task/1634
*/

#include <bits/stdc++.h>
using namespace std;
 
vector<int> dp(1e6+5, -1);
 
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
    
    queue<par> proximo;
    proximo.push({0, 0});
    
    while(proximo.empty()==false){
        int atual=proximo.front().x;
        int dist=proximo.front().y+1;
        
        if(atual > k){
            proximo.pop();
            continue;
        }
        
        for(int i=0; i<coins.size(); i++){
            if(atual+coins[i]<=k && dp[atual+coins[i]]==-1){
                dp[atual+coins[i]]=dist;
                
                if(atual+coins[i]==k){
                    break;
                }
                
                proximo.push({atual+coins[i], dist});
            }
        }
        proximo.pop();
    }
    
    cout << dp[k] << "\n";
    
    return 0;
}