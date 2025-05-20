/* https://codeforces.com/group/YgJmumGtHD/contest/102223/problem/K */

#include <bits/stdc++.h>
using namespace std;

int main(){
    int n; cin >> n;
    int total=0;
    
    if(n%2==1){
        total+=3+(n-3)/2;
        n--;
    }
    
    total += (n+2)*(n+1)/2;
    
    cout << total << "\n";
    
    return 0;
}