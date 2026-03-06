/* https://codeforces.com/contest/597/problem/A */

#include <bits/stdc++.h>
using namespace std;

#define int long long

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    
    int k, l, r; cin >> k >> l >> r;
    
    int total=0;
    if(l<=0 && 0<=r){
        total++;
    }
    
    if( (l<0) == (r<0) ){
        l = abs(l);
        r = abs(r);
        
        if(l > r){
            swap(l, r);
        }
        
        int temp = r/k;
        if(l>0){
            temp -= (l-1)/k;
        }
        total += temp;
    }
    else{
        total += abs(l)/k + abs(r)/k;
    }
    cout << total << "\n";
    
    return 0;
}