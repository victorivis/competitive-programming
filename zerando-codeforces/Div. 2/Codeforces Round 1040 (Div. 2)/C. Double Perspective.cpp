/* https://codeforces.com/contest/2130/problem/C */

#include <bits/stdc++.h>
using namespace std;

int main(){
    int t; cin >> t;
    while(t--){
        int n; cin >> n;
        map<int, int> posicoes;
        map<int, int> intervalo;
        
        vector<int> prefixo(2*n+10, 0);
        
        for(int i=0; i<n; i++){
            int a, b; cin >> a >> b;
            if(intervalo[a] < b){
                intervalo[a] = b;
                posicoes[a] = i+1;
            }
        }
        
        vector<int> resposta;
        for(auto it=posicoes.begin(); it!=posicoes.end(); it++){
            resposta.push_back(it->second);
        }
        
        sort(resposta.begin(), resposta.end());
        cout << resposta.size() << "\n";
        for(int num: resposta){
            cout << num << " ";
        }
        cout << "\n";
    }

    return 0;
}