/* https://codeforces.com/gym/348180/problem/E */

#include <bits/stdc++.h>
using namespace std;

void fatorar(int n){
    if(n==1){
        cout << "1 0\n";
        return;
    }
    
    map<int, int> fatores;
    int produto = 1;
    
    for(int i=2; i<=sqrt(n); i++){
        if(n%i==0){
            produto*=i;
            while(n%i==0){
                n/=i;
                fatores[i]++;
            }
        }
    }
    if(n!=1){
        produto*=n;
        fatores[n]++;
    }
    
    int maior=0;
    int menor=INT_MAX;
    
    for(auto& p: fatores){
        maior = max(p.second, maior);
        menor = min(p.second, menor);
    }
    
    int pot=1;
    int total=0;
    while(pot<maior){
        pot<<=1;
        total++;
    }
    
    if(!(maior==menor && maior==pot)){
        total++;
    }
    cout << produto << " " << total << "\n";
}

int main(){
    int n; cin >> n;
    fatorar(n);

    return 0;
}