/*
https://codeforces.com/contest/2063/problem/A
*/

#include <bits/stdc++.h>
using namespace std;

int main(){
    int t; cin >> t;
    while(t--){
        int l, r; cin >> l >> r;
        
        if(l==r && l==1){
            cout << "1\n";
        }
        else{
            cout << r-l << "\n";
        }
    }

    return 0;
}