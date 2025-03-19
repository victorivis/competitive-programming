/* https://codeforces.com/contest/1006/problem/A */

#include <bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    int t; cin >> t;
    while(t--){
        int x; cin >> x;
        cout << (x+x%2-1) << " ";
    }
    cout << "\n";
    
    return 0;
}