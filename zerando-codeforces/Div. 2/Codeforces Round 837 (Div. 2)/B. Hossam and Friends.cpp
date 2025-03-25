/* https://codeforces.com/contest/1771/problem/B */

#include <bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    int t; cin >> t;
    while(t--){
        int n, k; cin >> n >> k;
        vector<int> distances(n+1, n+1);
        
        for(int i=0; i<k; i++){
            int x, y; cin >> x >> y;
            if(x>y) swap(x, y);
            
            distances[x] = min(distances[x], y);
        }
        
        for(int i=n; i>1; i--){
            distances[i-1] = min(distances[i-1], distances[i]);
        }
        
        long long total=0;
        for(int i=1; i<=n; i++){
            total += distances[i]-i;
        }
        
        cout << total << "\n";
    }
    
    return 0;
}