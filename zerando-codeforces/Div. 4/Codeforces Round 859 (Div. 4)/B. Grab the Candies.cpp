/* https://codeforces.com/contest/1807/problem/B */

#include <bits/stdc++.h>
using namespace std;

int main(){
    int t; cin >>t;
    while(t--){
        int n; cin >> n;
        int par=0, impar=0;
        for(int i=0; i<n; i++){
            int x; cin >> x;
            if(x%2==0) par+=x;
            else impar+=x;
        }
        
        if(impar < par){
            cout << "YES\n";
        }
        else{
            cout << "NO\n";
        }
    }
    
    return 0;
}