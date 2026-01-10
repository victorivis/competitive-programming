/* https://codeforces.com/contest/2144/problem/C */

#include <bits/stdc++.h>
using namespace std;

const int mod = 998244353;

int main(){
    int t; cin >> t;
    while(t--){
        int n; cin >> n;
        vector<vector<int>> li(2, vector<int>(n));
        
        for(int k=0; k<2; k++){
            for(int i=0; i<n; i++){
                cin >> li[k][i];
            }
        }
        
        long long total=2;
        for(int i=1; i<n; i++){
            int cont=0;
            
            if(li[0][i-1]<=li[0][i] && li[1][i-1]<=li[1][i]) cont++;
            if(li[0][i-1]<=li[1][i] && li[1][i-1]<=li[0][i]) cont++;
            total = (total*cont)%mod;
        }
        cout << total << "\n";
    }
    
    return 0;
}