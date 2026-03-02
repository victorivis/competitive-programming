/* https://codeforces.com/contest/2184/problem/E */

#include <bits/stdc++.h>
using namespace std;

#define int long long
#define par array<long long,2>

int tri(int num){
    return num * (num+1) / 2;
}

const int inf = 1<<30;

int32_t main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    
    int t; cin >> t;
    while(t--){
        int n; cin >> n;
        vector<int> li(n);
        for(int i=0; i<n; i++){
            cin >> li[i];
        }
        
        vector<vector<int>> matriz(n+1);
        vector<int> dif(n-1);
        for(int i=0; i<n-1; i++){
            dif[i] = abs(li[i+1]-li[i]);
            matriz[dif[i]].push_back(i+1);
        }
        
        int total = tri(n-1);
        vector<int> resp = {total};
        
        map<par, bool> ranges;
        ranges[{1, n}] = true;
        
        for(int i=1; i<n-1; i++){
            for(int pos: matriz[i]){
                par p = prev(ranges.upper_bound({pos, inf}))->first;
                
                
                int soma = -tri(p[1]-p[0]) + tri(pos-p[0]) + tri(p[1] - (pos+1) );
                total += soma;
                
                ranges.erase(p);
                ranges[{p[0], pos}] = true;
                ranges[{pos+1, p[1]}] = true;
            }
            resp.push_back(total);
        }
        
        for(int num: resp){
            cout << num << " ";
        }
        cout << "\n";
    }
    
    return 0;
}