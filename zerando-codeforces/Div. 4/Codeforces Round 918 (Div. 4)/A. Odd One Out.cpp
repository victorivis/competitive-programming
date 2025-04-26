/* https://codeforces.com/contest/1915/problem/A */

#include <bits/stdc++.h>
using namespace std;

int main(){
    int t; cin >> t;
    while(t--){
        int a=0;
        for(int i=0; i<3; i++){
            int x; cin >> x;
            a^=x;
        }
        cout << a << "\n";
    }

    return 0;
}