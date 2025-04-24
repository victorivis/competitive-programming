/* https://codeforces.com/contest/1703/problem/G */

#include <bits/stdc++.h>
using namespace std;

const long long INF = LLONG_MAX;
const long long MINIMUM = LLONG_MIN;

int main(){
    int t; cin >> t;
    while(t--){
        int n, k; cin >> n >> k;
        vector<int> lista(n);
        
        for(int& i: lista){
            cin >> i;
        }
        
        vector<vector<int>> ganhos(1, lista);
        
        bool todosZero;
        int pos=1;
        do{
            todosZero=true;
            
            ganhos.push_back(vector<int>(n));
            
            for(int i=0; i<n; i++){
                ganhos[pos][i] = ganhos[pos-1][i]/2;
                if(ganhos[pos][i]!=0){
                    todosZero=false;
                }
            }
            
            pos++;
        } while(todosZero==false);
        
        vector<vector<long long>> dp(pos+3, vector<long long>(n, MINIMUM));
        
        for(int m=0; m<pos; m++){
            for(int i=0; i<n; i++){
                long long anterior = (i==0 ? 0 : dp[m][i-1]);
                long long ganhoAtual = (m+1!=pos ? ganhos[m][i]-k : 0);
                
                if(i>=m){
                    dp[m+1][i] = max(dp[m+1][i], anterior+ganhos[min(m+1, pos-1)][i]);
                }
                
                dp[m][i] = max(dp[m][i], anterior+ganhoAtual);
            }
        }
        
        long long maior=-1;
        for(int m=0; m<pos; m++){
            maior = max(maior, dp[m][n-1]);
        }
        
        cout << maior << "\n";
    }
    
    return 0;
}