/* https://codeforces.com/contest/1006/problem/B */

#include <bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    int n, dias; cin >> n >> dias;
    
    vector<pair<int, int>> lista(n);
    map<int, bool> d;
    
    for(int i=0; i<n; i++){
        int x; cin >> x;
        lista[i] = pair<int, int>(x, i+1);
    }
    sort(lista.begin(), lista.end(), greater<pair<int, int>>());
    
    long long total=0;
    
    vector<int> limites;
    for(int i=0; i<dias; i++){
        int pos = lista[i].second;
        limites.push_back(pos);
        total+=lista[i].first;
    }
    
    limites.push_back(n+1);
    sort(limites.begin(), limites.end());
    limites[0] = 1;
    
    cout << total << "\n";
    for(int i=1; i<limites.size(); i++) cout << limites[i] - limites[i-1] << " ";
    cout << "\n";
    
    return 0;
}