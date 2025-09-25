/* https://codeforces.com/contest/2020/problem/C */

#include <bits/stdc++.h>
using namespace std;

#define int long long
const int LIM = 61;
const int MAX = 1<<LIM;

int32_t main(){
    int t; cin >> t;
    
    while(t--){
        int b, c, d; cin >> b >> c >> d;
        
        bool possivel=true;
        long long resposta = 0;
        for(int i=0; i<LIM; i++){
            int xb = (b>>i)&1;
            int xc = (c>>i)&1;
            int xd = (d>>i)&1;
            
            for(int k=0; k<2; k++){
                bool temp = ((k|xb) - (k&xc)) == (xd);
                if(temp){
                    resposta |= (k<<i);
                    goto proximo;
                }
            }
            
            possivel=false;
            break;
            
            proximo:
            int besteira;
        }
        
        if(possivel){
            cout << resposta << "\n";
        }
        else{
            cout << "-1\n";
        }
    }
    
    return 0;
}