/* https://codeforces.com/contest/2184/problem/A */

#include <bits/stdc++.h>
using namespace std;

int main(){
    int t; cin >> t;
    while(t--){
        int n; cin >> n;
        if(n==2){
            cout << "2\n";
            continue;
        }
        if(n==3){
            cout << "3\n";
            continue;
        }
        cout << (n&1) << "\n";
    }

    return 0;
}