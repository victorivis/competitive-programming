/* https://codeforces.com/gym/348180/problem/D */

#include <bits/stdc++.h>
using namespace std;

long long computar(int n, int k){
    int vezes = n/k;
    
    long long total = vezes + n*(vezes-1ll)/2ll;
    return total;
}

void fatorar(int n){
    vector<int> fatores;
    for(int i=sqrt(n); i>=1; i--){
        if(n%i==0){
            fatores.push_back(i);
            if(i != n/i) fatores.push_back(n/i);
        }
    }
    
    vector<long long> resposta;
    for(int i=0; i<fatores.size(); i++){
        resposta.push_back(computar(n, fatores[i]));
    }
    
    sort(resposta.begin(), resposta.end());
    
    for(int i=0; i<resposta.size(); i++){
        cout << resposta[i] << " ";
    }
    cout << "\n";
}

int main(){
    int n; cin >> n;
    fatorar(n);

    return 0;
}