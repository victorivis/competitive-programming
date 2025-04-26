/* https://codeforces.com/contest/1829/problem/A */

#include <bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    int n; cin >> n;
    string s = "codeforces";
    
    for(int i=0; i<n; i++){
        int total=0;
        
        for(int j=0; j<s.size(); j++){
            char c; cin >> c;
            if(c!=s[j]) total++;
        }
        cout << total << "\n";
    }

    return 0;
}