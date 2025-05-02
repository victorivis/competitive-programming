/* https://codeforces.com/contest/2047/problem/A */

#include <bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    int t; cin >> t;
    while(t--){
        int n; cin >> n;
        vector<int> prefixo(n+1);
        
        int total=0;
        for(int i=0; i<n; i++){
            int x; cin >> x;
            prefixo[i+1] = prefixo[i] + x;
            
            double raiz = sqrt(prefixo[i+1]);
            if(prefixo[i+1]%2==1 && raiz == (int) raiz){
                total++;
            }
        }
        
        cout << total << "\n";
    }
    
    return 0;
}