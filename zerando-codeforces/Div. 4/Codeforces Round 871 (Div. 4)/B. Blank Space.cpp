/* https://codeforces.com/contest/1829/problem/B */

#include <bits/stdc++.h>
using namespace std;

int main(){
    int t; cin >> t;
    while(t--){
        int n; cin >> n;
        
        int maior=0;
        int atual=0;
        for(int i=0; i<n; i++){
            int x; cin >> x;
            if(x==0){
                atual+=1;
            }
            else{
                atual=0;
            }
            
            maior = max(maior, atual);
        }        
        cout << maior << "\n";
    }

    return 0;
}