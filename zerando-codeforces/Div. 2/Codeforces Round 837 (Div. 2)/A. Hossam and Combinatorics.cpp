/* https://codeforces.com/contest/1771/problem/A */

#include <bits/stdc++.h>
using namespace std;

int main(){
    int t; cin >> t;
    while(t--){
        int n; cin >> n;
        map<int, int> nums;
        for(int i=0; i<n; i++){
            int x; cin >> x;
            nums[x]++;
        }
        
        int lower = nums.begin()->second;
        int upper = nums.rbegin()->second;
        
        if(nums.size()>1){
            cout << 2ll*lower*upper << "\n";
        }
        else{
            cout << lower*(lower-1ll) << "\n";
        }
    }
    
    return 0;
}