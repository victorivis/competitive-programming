#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define par array<int,2>

int main(){
    int t; cin >> t;
    while(t--){
        int n; cin >> n;
        vector<int> peso(n+1);
        for(int i=1; i<=n; i++){
            cin >> peso[i];
            peso[i] = (peso[i]&1);
        }
        
        vector<vector<int>> g(n+1);
        for(int i=0; i<n-1; i++){
            int x, y; cin >> x >> y;
            g[x].pb(y);
            g[y].pb(x);
        }
        
        vector<bool> vis(n+1, false);
        queue<par> ordem;
        vector<int> sz(n+1);
        
        for(int i=1; i<=n; i++){
            sz[i] = g[i].size();
            
            if(sz[i] == 1){
                ordem.push({i, 0});
                vis[i] = true;
            } 
        }
        
        vector<int> prt(n+1);
        auto bfs = [&]() -> void {
            while(!ordem.empty()){
                par p = ordem.front();
                ordem.pop();
                
                int v = p[0];
                int dt = p[1];
                prt[v] = dt;
                
                for(auto& u: g[v]){
                    if(!vis[u]){
                        sz[u]--;
                        if(sz[u]<=1){
                            vis[u]=true;
                            ordem.push({u, dt+1});
                        }
                    }
                }
            }
        };
        bfs();
        
        vector<int> ngb(n+1, 0);
        
        vector<int> ans;
        vis.assign(n+1, false);
        
        set<par> st;
        for(int i=1; i<=n; i++){
            for(auto& u: g[i]){
                ngb[i] += peso[u];
            }

            if((peso[i]&1)!=(ngb[i]&1)){
                if(peso[i]&1){
                    st.insert({prt[i], i});
                }
                else{
                    vis[i]=true;
                    ans.push_back(i);
                }
            }
        }
        
        while(!st.empty()){
            par cur = *st.begin();
            st.erase(st.begin());
            
            int v = cur[1];
            vis[v] = true;
            ans.push_back(v);
            
            for(auto& u: g[v]){
                if(!vis[u]){
                    par el = {prt[u], u};
                    
                    if(st.count(el)!=0){
                        st.erase(el);
                    }
                    else if(peso[u]&1){
                        st.insert(el);
                    }
                    else{
                        vis[u]=true;
                        ans.push_back(u);
                    }
                }
            }
        }
        
        if(ans.size()==n){
            cout << "YES\n";
            for(int num: ans){
                cout << num << " ";
            } cout << "\n";
        }
        else{
            cout << "NO\n";
        }
    }

    return 0;
}