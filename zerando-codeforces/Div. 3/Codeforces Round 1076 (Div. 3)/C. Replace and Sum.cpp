/* https://codeforces.com/contest/2193/problem/C */

#include <bits/stdc++.h>
using namespace std;

#define int long long

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int t; cin >> t;
    while(t--){
        int n, q; cin >> n >> q;
        
        vector<vector<int>> li(2, vector<int>(n));
        for(int k=0; k<2; k++){
            for(int i=0; i<n; i++){
                cin >> li[k][i];
            }
        }
        
        for(int i=n-1; ~i; i--){
            int a = (i==n-1 ? 0 : li[0][i+1]);
            int b = li[1][i];
            li[0][i] = max({li[0][i], a, b});
        }
        
        vector<int> prefix(n+1);
        for(int i=0; i<n; i++){
            prefix[i+1] = prefix[i] + li[0][i];
        }
        
        while(q--){
            int l, r; cin >> l >> r;
            cout << prefix[r] - prefix[l-1] << " ";
        }
        cout << "\n";
    }
}