/* https://codeforces.com/contest/2180/problem/B */

#include <bits/stdc++.h>
using namespace std;

int main(){
    int t; cin >> t;
    while(t--){
        int n; cin >> n;
        
        vector<string> li(n);
        for(string& s: li){
            cin >> s;
        }
        
        string s = li[0];
        
        for(int i=1; i<n; i++){
            if(s + li[i] < li[i] + s){
                s = s+li[i];
            }
            else{
                s = li[i]+s;
            }
        }
        
        cout << s;
        cout << "\n";
    }

    return 0;
}