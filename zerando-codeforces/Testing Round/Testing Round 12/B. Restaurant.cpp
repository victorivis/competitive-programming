/* https://codeforces.com/contest/597/problem/B */

#include <bits/stdc++.h>
using namespace std;

#define par array<int,2>

int main(){
    int n; cin >> n;
    map<int, int> d;
    
    vector<par> li(n);
    for(int i=0; i<n; i++){
        cin >> li[i][0] >> li[i][1];
        li[i][1]++;
        
        d[li[i][0]]=-1;
        d[li[i][1]]=-1;
    }
    
    int cont=1;
    for(auto& p: d){
        p.second = cont++;
    }
    
    sort(li.begin(), li.end());
    
    stack<par> fila;
    for(auto& p: li){
        p[0] = d[p[0]];
        p[1] = d[p[1]];
        
        fila.push(p);
    }
    
    vector<int> dp(cont+3, 0);
    
    for(int i=cont; i>=0; i--){
        dp[i] = max(dp[i], dp[i+1]);
        
        while(!fila.empty() && fila.top()[0]==i){
            int fim = fila.top()[1];
            dp[i] = max(dp[i], 1+dp[fim]);
            fila.pop();
        }
    }
    
    cout << dp[0] << "\n";
    
    return 0;
}