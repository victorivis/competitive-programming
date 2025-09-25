/* https://codeforces.com/contest/2098/problem/C */

#include <bits/stdc++.h>
using namespace std;

int main(){
    int t; cin >> t;
    
    while(t--){
        map<int, int> dias;
        int n; cin >> n;
        for(int i=0; i<n; i++){
            int x; cin >> x;
            dias[x]++;
        }
        
        bool possivel=false;
        
        int cur=-1;
        for(auto [l, r]: dias){
            if(r>=4){
                possivel=true;
                break;
            }
            else if(r>=2){
                if(dias[l-1]>=2 || dias[l+1]>=2 || cur==l-1){
                    possivel=true;
                    break;
                }
                cur=l;
            }
            else if(r>=1){
                if(cur == l-1){
                   cur = l;   
                }
            }
        }
        cout << (possivel ? "Yes" : "No") << "\n";
    }
    
    return 0;
}