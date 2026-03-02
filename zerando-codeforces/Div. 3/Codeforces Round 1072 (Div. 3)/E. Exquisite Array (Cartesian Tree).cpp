/* https://codeforces.com/contest/2184/problem/E */

#include <bits/stdc++.h>
using namespace std;

#define int long long

using T = array<int,2>;
struct rmq {
  vector<vector<T>> t;

  rmq() {}
  rmq(const vector<T> &a) {
    int n = a.size(), lg = __lg(n);
    t = vector<vector<T>>(lg + 1, vector<T>(n));
    for(int i=0; i<n; i++) t[0][i] = a[i];
    for (int i = 1; (1 << i) <= n; i++) for (int j = 0; j + (1 << i) <= n; j++)
      t[i][j] = min(t[i - 1][j], t[i - 1][j + (1 << (i - 1))]);
  }

  T query(int l, int r) {
    if (l > r) swap(l, r);
    int lg = __lg(r - l + 1);
    return min(t[lg][l], t[lg][r - (1 << lg) + 1]);
  }
};

int32_t main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    
    int t; cin >> t;
    while(t--){
        int n; cin >> n;
        vector<int> li(n);
        for(int i=0; i<n; i++){
            cin >> li[i];
        }
        
        vector<T> pos(n-1);
        for(int i=1; i<n; i++){
            pos[i-1] = {abs(li[i] - li[i-1]), i-1};
        }
        
        map<T, int> d;
        rmq st(pos);
        auto req = [&](auto& req, int l, int r) -> void {
            if(l>r) return;
            if(l==r){
                d[{l,l}] = l;
                return;
            }
            
            int pos = st.query(l, r)[1];
            d[{l, r}] = pos;
            req(req, l, pos-1);
            req(req, pos+1, r);
        };
        req(req, 0, n-2);
        
        vector<int> tot(n, 0);
        for(auto& [op, x]: d){
            int r = x-op[0] + 1;
            int l = op[1]-x + 1;
            int val = pos[x][0];
            
            tot[val] += l*r;
        }
        
        for(int i=n-2; ~i; i--){
            tot[i] = tot[i] + tot[i+1];
        }
        
        for(int i=1; i<tot.size(); i++){
            cout << tot[i] << " ";
        }
        cout << "\n";
    }
    
    return 0;
}