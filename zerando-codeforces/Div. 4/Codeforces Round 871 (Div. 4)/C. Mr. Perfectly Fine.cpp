/* https://codeforces.com/contest/1829/problem/C */

#include <bits/stdc++.h>
using namespace std;

int main(){
    int t; cin >> t;
    while(t--){
        int n; cin >> n;
        
        int both = INT_MAX;
        int a=INT_MAX, b=INT_MAX;
        int menor = INT_MAX;
        
        for(int i=0; i<n; i++){
            int x; cin >> x;
            string s; cin >> s;
            
            if(s[0]=='1' && s[1]=='1'){
                both=min(both, x);
            }
            else if(s[0]=='1'){
                a=min(a, x);
            }
            else if(s[1]=='1'){
                b=min(b, x);
            }
        }
        
        if(a!=INT_MAX && b!=INT_MAX){
            menor = a+b;
        }
        if(both!=INT_MAX){
            menor = min(menor, both);
        }
        
        if(menor==INT_MAX){
            cout << "-1\n";
        }
        else{
            cout << menor << "\n";
        }
    }

    return 0;
}