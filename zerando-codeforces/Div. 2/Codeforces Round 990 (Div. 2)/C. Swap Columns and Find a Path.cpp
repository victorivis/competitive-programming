/* https://codeforces.com/contest/2047/problem/C */

#include <bits/stdc++.h>
using namespace std;

#define int long long

int32_t main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    int t; cin >> t;
    while(t--){
        int n; cin >> n;
        vector<vector<int>> m(2, vector<int>(n));
        
        vector<int> antes;
        vector<int> depois;
        
        for(int j=0; j<2; j++){
            for(int i=0; i<n; i++){
                cin >> m[j][i];
            }
        }
        
        for(int i=0; i<n; i++){
            int soma = m[0][i] + m[1][i];
            
            if(m[0][i] > m[1][i]){
                antes.push_back(i);
            }
            else{
                depois.push_back(i);
            }
        }
        
        int total=0;
        int complementar=-1e6;
        for(int i=0; i<antes.size(); i++){
            int atual = antes[i];

            total += m[0][atual];            
            
            complementar = max(complementar, m[1][atual]);
        }
        
        for(int i=0; i<depois.size(); i++){
            int atual = depois[i];
            
            total += m[1][atual];
            complementar = max(complementar, m[0][atual]);
        }
        total += complementar;
        
        cout << total << "\n";
    }
    
    return 0;
}