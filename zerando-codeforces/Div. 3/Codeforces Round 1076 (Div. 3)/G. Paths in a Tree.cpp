/* https://codeforces.com/contest/2193/problem/G */

#include <bits/stdc++.h>
using namespace std;

int query(int a, int b){
    cout << "? " << a << " " << b << endl;
    int x; cin >> x;
    assert(x!=-1);
    return x;
}

int answer(int a){
    cout << "! " << a << endl;
    return 1;
}

#define par array<int,2>

int main(){
    int t; cin >> t;
    int r = 100;
    while(t--){
        int n; cin >> n;
        vector<vector<int>> li(n+1);
        for(int i=0; i<n-1; i++){
            int x, y; cin >> x >> y;
            li[x].push_back(y);
            li[y].push_back(x);
        }
        
        vector<int> leafs;
        for(int i=1; i<=n; i++){
            if(li[i].size()==1){
                leafs.push_back(i);
            }
        }
        int cont=1;
        
        vector<par> booyah;
        int ultimo;
        auto dfs = [&](auto& dfs, int v, int p) -> void {
            cont++;
            
            if(cont&1){
                booyah.push_back({v, ultimo});
            }
            else{
                ultimo = v;
            }
            
            for(auto& u: li[v]){
                if(u!=p){
                    dfs(dfs, u, v);
                }
            }
        };
        dfs(dfs, leafs[0], -1);
        
        par ans={ultimo, ultimo};
        for(auto& p: booyah){
            if(query(p[0], p[1]) == 1){
                ans = p;
                break;
            }
        }
        
        if(ans[0] == ans[1] || query(ans[0], ans[0]) == 1){
            answer(ans[0]);
        }
        else{
            answer(ans[1]);
        }
    }

    return 0;
}