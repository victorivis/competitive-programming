/* https://codeforces.com/contest/776/problem/B */

#include <bits/stdc++.h>
using namespace std;

#define ll long long

const int lim = 1.5e5;
int primo[lim] = {0};

void crivo(){
    primo[0] = primo[1] = 1;
    for(ll i=2; i<lim; i++){
        if(primo[i] == 0){
            primo[i]=i;
            for(ll j=i*i; j<lim; j+=i){
                primo[j]=i;
            }
        }
    }
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    
    crivo();
    
    int n; cin >> n;
    if(n>2){
        cout << "2\n";
    }
    else{
        cout << "1\n";
    }
    
    for(int i=2; i<=n+1; i++){
        if(primo[i] == i) cout << "1 ";
        else cout << "2 ";
    }
    cout << "\n";

    return 0;
}