/* https://codeforces.com/contest/2193/problem/D */

#include <bits/stdc++.h>
using namespace std;

#define int long long

const int inf = 1ll<<60;

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int t; cin >> t;
    while(t--){
        int n; cin >> n;
        
        deque<int> swd(n);
        for(int i=0; i<n; i++){
            cin >> swd[i];
        }
        sort(swd.begin(), swd.end());
        
        vector<int> mnt(n);
        vector<int> pref(n+1, 0);
        for(int i=0; i<n; i++){
            cin >> mnt[i];
            pref[i+1] = pref[i]+mnt[i];
        }
        
        int maior=0;
        while(!swd.empty()){
            int cur = swd[0];
            int sz = swd.size();
            int lvl = prev(upper_bound(pref.begin(), pref.end(), sz)) - pref.begin();
            if(sz >= pref.back()) lvl = n;
            
            while(!swd.empty() && swd[0]==cur){
                swd.pop_front();
            }
            
            maior = max(maior, lvl*cur);
        }
        
        cout << maior << "\n";
    }
}