/* https://codeforces.com/gym/348180/problem/C */

#include <bits/stdc++.h>
using namespace std;

int main(){
    int t; cin >> t;
    while(t--){
        int n, k; cin >> n >> k;
        k--;
        
        if(n%2==0){
            cout << (k%n+1) << "\n";
        }
        else{
            int encontro = n/2;
            int total = k/(encontro)*(encontro+1) + k%(encontro);
            
            cout << (total%n+1) << "\n";
        }
    }

    return 0;
}