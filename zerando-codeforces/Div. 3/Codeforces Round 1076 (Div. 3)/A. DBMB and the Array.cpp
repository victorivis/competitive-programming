/* https://codeforces.com/contest/2193/problem/A */

#include <bits/stdc++.h>
using namespace std;

#define int long long

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int t; cin >> t;
    while(t--){
        int n, x, s; cin >> n >> s >> x;
        
        int tot=0;
        for(int i=0; i<n; i++){
            int temp; cin >> temp;
            tot+=temp;
        }
        int result = s-tot;
        
        bool possivel=false;
        if(result>=0 && (result%x==0)){
            possivel=true;
        }
        cout << (possivel ? "YES" : "NO") << "\n";
    }
}