/*
https://judge.beecrowd.com/en/runs/code/43499422
*/

#include <bits/stdc++.h>
using namespace std;

int main(){
    int n; cin >> n;
    
    vector<int> even;
    vector<int> odd;
    
    for(int i=0; i<n; i++){
        int x; cin >> x;
        
        if(x%2==0){
            even.push_back(x);
        }
        else{
            odd.push_back(x);
        }
    }
    
    sort(even.begin(), even.end());
    sort(odd.begin(), odd.end(), greater<int>());
    
    for(int i: even) cout << i << "\n";
    
    for(int i: odd) cout << i << "\n";
    
    return 0;
}