/* https://codeforces.com/contest/2162/problem/C */

#include <bits/stdc++.h>
using namespace std;

int lg2(int num){
    int cont=0;
    while(num > 0){
        num/=2;
        cont++;
    }
    return cont;
}

int main(){
    int t; cin >> t;
    while(t--){
        int a, b; cin >> a >> b;
        
        if(lg2(a) < lg2(b)){
            cout << "-1\n";
            continue;
        }
        
        vector<int> resposta;
        for(int i=0; i<=lg2(a); i++){
            if((a>>i&1) != (b>>i&1)){
                resposta.push_back(1<<i);
            }
        }
        
        cout << resposta.size() << "\n";
        if(!resposta.empty()){
            for(int num: resposta){
                cout << num << " ";
            }
            cout << "\n";
        }
    }

    return 0;
}