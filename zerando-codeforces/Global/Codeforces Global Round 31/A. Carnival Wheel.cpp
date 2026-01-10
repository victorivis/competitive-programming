/* https://codeforces.com/contest/2144/problem/C */

#include <bits/stdc++.h>
using namespace std;

int main(){
    int t; cin >> t;
    while(t--){
        int n, b, g; cin >> n >> b >> g;
        int a = gcd(n, g);
        if(a==0) cout << b << "\n";
        cout << ((n-1)-b)/a * a + b << "\n";
    }
    
    return 0;
}