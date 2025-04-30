/* https://codeforces.com/gym/348180/problem/G */

#include <bits/stdc++.h>
using namespace std;

#define int long long

int32_t main(){
    int t; cin >> t;
    while(t--){
        int x, y; cin >> y >> x;
        
        int cont=1;
        long long total=0;
        while(true){
            int a = x-cont;
            int b = (y-cont)/cont - cont;
            int atual = min(a, b);
            
            if(atual<=0) break;
            total+=atual;
            cont++;
        }
        
        cout << total << "\n";
    }

    return 0;
}