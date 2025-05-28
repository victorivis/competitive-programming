/*
https://cses.fi/problemset/task/2413/
*/

#include <bits/stdc++.h>
using namespace std;

const int modulo = 1e9+7;

int main(){
    int n=1e6;
    long long x=1, y=1;
    vector<int> dp(n+1);
    
    for(int i=0; i<n; i++){
        long long novoX = 4*x+y;
        long long novoY = x+2*y;
        
        dp[i]=(x+y)%modulo;
        
        x=(novoX)%modulo;
        y=(novoY)%modulo;
    }
    
    int t; cin >> t;
    while(t--){
        int x; cin >> x;
        cout << dp[x-1] << "\n";
    }

    return 0;
}