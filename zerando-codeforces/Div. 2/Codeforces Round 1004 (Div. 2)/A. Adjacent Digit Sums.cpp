/*
https://codeforces.com/contest/2067/problem/A
*/

#include <bits/stdc++.h>
using namespace std;

const int LIM = 1e3;

int main(){
    int t; cin >> t;
    while(t--){
        int x, y; cin >> x >> y;
        int parteNove = x-(y-1);
        
        if(parteNove>=0 && parteNove%9==0){
            cout << "YES\n";
        }
        else{
            cout << "NO\n";
        }
    }
    
    return 0;
}