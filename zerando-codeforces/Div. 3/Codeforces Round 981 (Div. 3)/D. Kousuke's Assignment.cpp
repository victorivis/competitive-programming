/*
https://codeforces.com/contest/2033/problem/D
*/

#include <bits/stdc++.h>
using namespace std;

int main(){
    int t; cin >> t;
    while(t--){
        int n; cin >> n;
        vector<int> lista(n);
        map<long long, int> d;
        d[0]=1;
        
        int total=0;
        long long pref=0;
        
        for(int i=0; i<n; i++){
            int x; cin >> x;
            pref += x;
            
            d[pref]++;
            if(d[pref]==2){
                total++;
                d={{0, 1}};
                pref=0;
            }
        }
        cout << total << "\n";
    }

    return 0;
}