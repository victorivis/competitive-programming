/* https://codeforces.com/contest/2020/problem/B */

#include <bits/stdc++.h>
using namespace std;

#define int long long

int triangular(int n){
    return n*(n+1);
}

const int LIM = 2e18;

int lower(int num){
    int l=0;
    int r=sqrt(LIM)+1;
    
    int pos=0;
    while(l<=r){
        int mid = (l+r)/2;
        
        if(triangular(mid) >= num){
            pos = mid;
            r = mid-1;
        }
        else{
            l = mid+1;
        }
    }
    
    return pos;
}

int32_t main(){
    int t; cin >> t;
    while(t--){
        int k; cin >> k;
        
        int dist = lower(k);
        
        int result = k+dist;
        cout << result << "\n";
    }

    return 0;
}