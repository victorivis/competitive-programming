/* https://codeforces.com/contest/2180/problem/C */

#include <bits/stdc++.h>
using namespace std;

#define int long long

int32_t main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    
    int t; cin >> t;
    while(t--){
        int n, k; cin >> n >> k;
        
        int total=0;
        int oxor=0;
        if(k%2==0){
            int cont=0;
            int extra = popcount<unsigned>(n) - (popcount<unsigned>(n)&1);
            int lim = min(k, extra);
            vector<int> chute(lim, 0);
            
            int a=0;
            int b=0;
            for(int i=30; i>=0; i--){
                if(n>>i&1){                    
                    for(int f=0; f<lim; f++){
                        if(cont == f || (cont>=lim && f==0)) continue;
                        chute[f] += 1<<i;
                    }
                    cont++;
                }
                else{
                    for(int j=0; j<min(cont - (cont&1), lim); j++){
                        chute[j] += 1<<i;
                    }
                }
            }
            
            for(int num: chute){
                cout << num << " ";
                oxor ^= num;
            }
            
            k-=lim;
            
            if(lim == 0){
                cout << "0 ";
                k--;
            }
        }
        
        while(k--){
            cout << n << " ";
            oxor ^= n;
        }
        cout << "\n";
        
        assert(oxor == n);
    }

    return 0;
}