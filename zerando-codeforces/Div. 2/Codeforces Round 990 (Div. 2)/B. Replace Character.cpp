/* https://codeforces.com/contest/2047/problem/B */

#include <bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    int t; cin >> t;
    while(t--){
        int n; cin >> n;
        string s; cin >> s;
        
        unordered_map<char, int> d;
        
        pair<int, char> maior(0, '1');
        for(int i=0; i<n; i++){
            char atual = s[i];
            d[atual]++;
            
            if(d[atual]>maior.first){
                maior = pair<int, char>(d[atual], atual);
            }
        }
        
        
        int minimo=INT_MAX;
        for(auto p=d.begin(); p!=d.end(); p++){
            minimo = min(minimo, p->second);
        }
        
        char menor;
        for(auto p=d.begin(); p!=d.end(); p++){
            if(p->second==minimo && p->first != maior.second){
                menor = p->first;
            }
        }
        
        for(int i=0; i<n; i++){
            if(s[i]==menor){
                s[i]=maior.second;
                break;
            }
        }
        
        cout << s << "\n";
    }
    
    return 0;
}