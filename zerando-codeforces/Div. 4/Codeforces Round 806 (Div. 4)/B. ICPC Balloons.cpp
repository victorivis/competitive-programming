/* https://codeforces.com/contest/1703/problem/B */

#include <bits/stdc++.h>
using namespace std;

int lg2(int n){
    int total=0;
    while(n>0){
        n/=2;
        total++;
    }
    return total;
}

int main(){
    int t; cin >> t;
    while(t--){
        int n; cin >> n;
        vector<int> l(26);
        
        for(int i=0; i<n; i++){
            char c; cin >> c;
            int pos = c - 'A';
            if(l[pos]==0) l[pos]++;
            l[pos]++;
        }
        
        int total=0;
        for(int i=0; i<26; i++){
            total+=l[i];
        }
        
        cout << total << "\n";
    }

    return 0;
}