/*
https://cses.fi/problemset/task/1145
*/

#include <bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    int n; cin >> n;
    vector<int> l;
    
    for(int i=0; i<n; i++){
        int x; cin >> x;
        
        auto busca = lower_bound(l.begin(), l.end(), x);
        if(busca == l.end()){
            l.push_back(x);
        }
        else{
            *busca = x;
        }
    }
    
    cout << l.size() << "\n";
    
    return 0;
}