/*
https://codeforces.com/contest/2071/problem/D1
*/

#include <bits/stdc++.h>
using namespace std;

#define int long long

int n;
vector<int> prefixo;
map<int, int> nums;

int dp(int pos){
    if(nums.count(pos)==0){
        int metade = pos/2;
        
        if(metade<=n){
            nums[pos] = prefixo[metade];
        }
        else if(metade%2==0){
            nums[pos] = dp(metade) ^ prefixo[n];
        }
        else{
            nums[pos] = prefixo[n];
        }
        
        int resultado = dp(metade);
    }
    
    return nums[pos];
}

int32_t main(){
    int t; cin >> t;
    
    while(t--){
        int l, r; cin >> n >> l >> r;
        prefixo.assign(n+2, 0);
        nums = {};
        
        for(int i=1; i<=n; i++){
            int x; cin >> x;
            nums[i]=x;
            prefixo[i] = prefixo[i-1]^x;
        }
        
        if(n%2==0){
            nums[n+1] = prefixo[n/2];
            prefixo[n+1] = nums[n+1] ^ prefixo[n];
            n+=1;
        }
        
        int atual = dp(l);
        cout << atual << "\n";
    }

    return 0;
}