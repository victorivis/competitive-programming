/* https://codeforces.com/contest/1006/problem/D */

#include <bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    int n; cin >> n;
    string a, b; cin >> a >> b;
    
    int total=0;
    for(int i=0; i<n/2; i++){
        int copia = total;
        
        int inverso = n-i-1;
        
        map<char, int> d;
        
        int maior=0;
        
        d[a[i]]++;
        d[a[inverso]]++;
        d[b[i]]++;
        d[b[inverso]]++;
        
        for(auto& par: d){
            maior = max(maior, par.second);
        }
        
        total += max((int)d.size() - 2, 0);
        if(d.size()==2 && maior==3) total++;
        if(d.size()==3 && a[i] == a[inverso]) total++;
    }
    
    if(n%2==1){
        int meio = n/2;
        if(a[meio] != b[meio]) total++;
    }
    
    cout << total << "\n";
    
    return 0;
}