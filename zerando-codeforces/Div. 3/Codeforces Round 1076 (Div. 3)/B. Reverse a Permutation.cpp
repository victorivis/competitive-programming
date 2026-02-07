/* https://codeforces.com/contest/2193/problem/B */

#include <bits/stdc++.h>
using namespace std;

#define int long long

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int t; cin >> t;
    while(t--){
        int n; cin >> n;
        
        vector<int> li(n);
        vector<int> rev(n);
        for(int i=0; i<n; i++){
            cin >> li[i]; li[i]--;
            rev[li[i]] = i;
        }
        
        int pos=n-1;
        for(int i=0; i<n; i++){
            if(li[i]!=pos){
                int l = i, r = rev[pos];
                if(l>r) swap(l, r);
                reverse(li.begin()+l, li.begin()+r+1);
                break;
            }
            pos--;
        }
        
        for(auto& p: li){
            cout << p+1 << " ";
        } cout << "\n";
    }
}