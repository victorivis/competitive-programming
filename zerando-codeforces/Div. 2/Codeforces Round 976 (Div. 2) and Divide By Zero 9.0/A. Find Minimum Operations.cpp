/* https://codeforces.com/contest/2020/problem/A */

#include <bits/stdc++.h>
using namespace std;

#define teste int teste; cin >> teste;while(teste--)
#define int long long

int32_t main(){
    teste{
        int n, k; cin >> n >> k;
        int pot = k;
        
        int total=0;
        
        if(k==1){
            cout << n << "\n";
        }
        else{
            while(n!=0){
                while(pot<n){
                    pot*=k;
                }
                
                if(pot!=n){
                    pot/=k;
                }
                
                int vezes = n/pot;
                total+=vezes;
                n -= pot*vezes;
            }
            
            cout << total << "\n";
        }
    }

    return 0;
}