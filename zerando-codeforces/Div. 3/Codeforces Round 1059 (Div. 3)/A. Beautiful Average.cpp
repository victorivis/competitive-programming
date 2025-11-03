/* https://codeforces.com/contest/2162/problem/A */

#include <bits/stdc++.h>
using namespace std;

int main(){
    int t; cin >> t;
    while(t--){
        int n; cin >> n;
        int num=0;
        
        for(int i=0; i<n; i++){
            int x; cin >> x;
            num = max(num, x);
        }
        
        cout << num << "\n";
    }
    
    return 0;
}