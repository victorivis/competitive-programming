/* https://codeforces.com/contest/2078/problem/A */

#include <bits/stdc++.h>
using namespace std;

int main(){
    int t; cin >> t;
    while(t--){
        int n, k; cin >> n >> k;
        
        int total=0;
        for(int i=0; i<n; i++){
            int x; cin >> x;
            total+=x;
        }
        
        double media = (double) total / n;
        if(media == k){
            cout << "YES\n";
        }
        else{
            cout << "NO\n";
        }
    }
    
    return 0;
}