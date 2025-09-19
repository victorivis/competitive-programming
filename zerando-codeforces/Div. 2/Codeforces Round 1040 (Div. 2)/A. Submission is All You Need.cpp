/* https://codeforces.com/contest/2130/problem/A */

#include <bits/stdc++.h>
using namespace std;

int main(){
    int t; cin >> t;
    while(t--){
        int n; cin >> n;
        int total=0;
        for(int i=0; i<n; i++){
            int x; cin >> x;
            total += x ? x : 1;
        }
        
        std::cout << total << std::endl;
    }

    return 0;
}