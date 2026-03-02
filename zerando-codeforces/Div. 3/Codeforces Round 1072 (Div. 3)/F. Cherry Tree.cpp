/* https://codeforces.com/contest/2184/problem/F */

#include <bits/stdc++.h>
using namespace std;

int combinar(int a, int b){
    if(a==0){
        return b;
    }
    if(b==0){
        return a;
    }
    
    int result=0;
    for(int i=0; i<3; i++){
        if(a>>i&1){
            for(int j=0; j<3; j++){
                if(b>>j&1){
                    result |= 1<<((i+j)%3);
                }
            }
        }
    }
    return result;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    
    int t; cin >> t;
    while(t--){
        int n; cin >> n;
        vector<vector<int>> grafo(n+1);
        for(int i=0; i<n-1; i++){
            int x, y; cin >> x >> y;
            grafo[x].push_back(y);
            grafo[y].push_back(x);
        }
        
        vector<int> dp(n+1);
        auto dfs = [&](auto& dfs, int x, int p) -> int {
            bool folha=true;
            int extra=0;
            for(auto& v: grafo[x]){
                if(v!=p){
                    folha=false;
                    extra = combinar(extra, dfs(dfs, v, x));
                }
            }
            int temp = 1<<1;
            int result = extra | temp;
            
            return result;
        };
        
        int total = dfs(dfs, 1, -1);        
        if(total&1){
            cout << "YES\n";
        }
        else{
            cout << "NO\n";
        }
    }
    
    return 0;
}