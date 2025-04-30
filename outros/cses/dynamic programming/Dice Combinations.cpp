/* https://cses.fi/problemset/task/1633 */

#include <bits/stdc++.h>
using namespace std;

vector<int> dp(1e6+5, -1);
vector<int> moedas = {1, 2, 3, 4, 5, 6};
const int modulo = 1e9+7;

int calcular(int n){    
    if(dp[n]==-1){
        long long total=0;
        
        for(int i: moedas){
            int subproblema = n-i;
            
            if(subproblema>=0){
                total = (total + calcular(subproblema))%modulo;
            }
            else{
                break;
            }
        }
        
        dp[n]=total;
    }
    return dp[n];
}

int main(){
    dp[0]=1;
    
    int n; cin >> n;
    cout << calcular(n) << "\n";

    return 0;
}