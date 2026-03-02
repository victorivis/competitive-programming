/* https://codeforces.com/contest/2184/problem/B */

#include <bits/stdc++.h>
using namespace std;

#define int long long

int32_t main(){
    int t; cin >> t;
    while(t--){
        int n, m, k; cin >> n >> m >> k;
        
        int passou = k - (k/m*m);
        int pos = (k/m)&1;
        
        int total;
        if(m>=n){
            total = max(0ll, n - passou);
        }
        else{
            int a = n;
            int b = m;
            
            if(!pos){
                total = max(0ll, a-passou);
            }
            else{
                total = max(0ll, b-passou);
            }
        }
        
        cout << total << "\n";
    }

    return 0;
}