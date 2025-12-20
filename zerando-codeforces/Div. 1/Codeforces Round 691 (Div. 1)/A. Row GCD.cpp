/* https://codeforces.com/problemset/problem/1458/a */

#include <bits/stdc++.h>
using namespace std;

#define int long long

int32_t main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    
    int n, m; cin >> n >> m;
    vector<int> li(n), extra(m);
    
    for(int& x: li){
        cin >> x;
    }
    
    for(int& x: extra){
        cin >> x;
    }
    
    sort(li.begin(), li.end());
    int uau = 0;
    
    for(int i=1; i<n; i++){
        uau = gcd(uau, li[i] - li[i-1]);
    }
    
    for(int x: extra){
        cout << gcd(li[0]+x, uau) << " ";
    }

    return 0;
}