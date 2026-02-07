/* https://codeforces.com/contest/2193/problem/E */

#include <bits/stdc++.h>
using namespace std;

const int inf = 1<<30;

int main(){
    int t; cin >> t;
    while(t--){
        int n; cin >> n;
        set<int> st;
        for(int i=0; i<n; i++){
            int x; cin >> x;
            st.insert(x);
        }
        
        unordered_map<int,int> dp;
        auto divi = [&](auto& divi, int num) -> int {
            if(dp.count(num)==0){
                if(st.count(num)!=0){
                    dp[num]=1;
                    return 1;
                }
                
                int minimo = inf;
                for(int i=2; i<=sqrt(num); i++){
                    if(num%i==0){
                        int a = divi(divi, i);
                        int b = divi(divi, num/i);
                        
                        if(a==-1 || b==-1) continue;
                        minimo = min(minimo, a+b);
                    }
                }
                
                if(minimo==inf) minimo = -1;
                dp[num] = minimo;
            }
            return dp[num];
        };
        
        for(int i=1; i<=n; i++){
            cout << divi(divi, i) << " ";
        } cout << "\n";
    }

    return 0;
}