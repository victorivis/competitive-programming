/*
https://cses.fi/problemset/task/1745
*/

#include <bits/stdc++.h>
using namespace std;
 
void mostrar(vector<vector<bool>>& dp){
    for(int i=0; i<dp.size(); i++){
        for(int j=0; j<dp[i].size(); j++){
            cout << dp[i][j] << " ";
        }
        cout << "\n";
    }
}
 
int main(){
    int n; cin >> n;
    vector<int> l(n);
    
    long long total=0;
    
    for(int& i: l){
        cin >> i;
        total+=i;
    }
    
    sort(l.begin(), l.end());
    
    
    vector<vector<bool>> dp(n+1, vector<bool>(total+1, false));
    dp[0][0]=true;
    
    for(int i=1; i<=n; i++){
        for(int j=0; j<=total-l[i-1]; j++){
            if(dp[i-1][j]){
                dp[i][j]=true;
                dp[i][j+l[i-1]]=true;
            }
        }
    }
    
    queue<int> resultados;
    int soma=0;
    for(int i=1; i<=total; i++){
        if(dp[n][i]){
            resultados.push(i);
            soma++;
        }
    }
    
    cout << soma << "\n";
    while(resultados.empty()==false){
        cout << resultados.front() << " ";
        resultados.pop();
    }
    cout << "\n";
    
    return 0;
}