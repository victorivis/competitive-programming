/* https://codeforces.com/contest/597/problem/B */

#include <bits/stdc++.h>
using namespace std;

#define par array<int,2>
const int inf = 1<<30;

int main(){
    int n; cin >> n;
    map<int, int> d;
    
    vector<par> li(n);
    for(int i=0; i<n; i++){
        cin >> li[i][0] >> li[i][1];        
        d[li[i][0]]=-1;
        d[li[i][1]]=-1;
    }
    
    int cont=1;
    for(auto& p: d){
        p.second = cont++;
    }
    
    auto comp = [](par& x, par& y){
        return x[0] > y[0];
    };
    sort(li.begin(), li.end(), comp);
    
    int ultimo = inf;
    int total=0;
    for(auto& p: li){
        if(p[1] < ultimo){
            ultimo = p[0];
            total++;
        }
    }
    
    cout << total << "\n";
    
    return 0;
}