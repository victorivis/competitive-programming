/* https://codeforces.com/contest/2078/problem/B */

#include <bits/stdc++.h>
using namespace std;

int main(){
    int t; cin >> t;
    while(t--){
        int n, k; cin >> n >> k;
        
        if(k%2==1){
            for(int i=1; i<=n; i++){
                if(i!=n){
                    cout << n << " ";
                }
                else{
                    cout << n-1 << " ";
                }
            }
            cout << "\n";
        }
        else{
            for(int i=1; i<=n; i++){
                if(i==n-1){
                    cout << n << " ";
                }
                else{
                    cout << n-1 << " ";
                }
            }
            cout << "\n";
        }
    }

    return 0;
}