/* https://codeforces.com/contest/2145/problem/C */

#include <bits/stdc++.h>
using namespace std;

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    
    int t; cin >> t;
    while(t--){
        int n; cin >> n;
        string s; cin >> s;        
        
        vector<int> pref(n+1);
        int atual=0;
        map<int, vector<int>> d;
        
        for(int i=0; i<n; i++){
            atual += (s[i]=='a') ? 1 : -1;
            
            d[atual].push_back(i);
            pref[i+1] = atual;
        }
        
        int minimo = n;
        for(int i=0; i<n; i++){
            if(pref[i+1] == atual){
                minimo = min(minimo, i+1);
            }
            if(pref[i+1]==0){
                minimo = min(minimo, n-(i+1));
            }

            int obj = atual + pref[i+1];            
            if(d.count(obj) == 0) continue;
            
            auto pos = upper_bound(d[obj].begin(), d[obj].end(), i);
            if(pos != d[obj].end()){
                minimo = min(minimo, (*pos-i));
            }
        }
        
        cout << (minimo==n ? -1 : minimo) << "\n";
    }
}