/* https://codeforces.com/contest/2193/problem/F */

#include <bits/stdc++.h>
using namespace std;

#define int long long

const int inf = 1ll<<60;
#define par array<long long,2>

signed main(){
    int t; cin >> t;
    while(t--){
        int n; cin >> n;
        par A, B; cin >> A[0] >> A[1] >> B[0] >> B[1];
        
        vector<par> li;
        
        for(int i=0; i<n; i++){
            par x; cin >> x[0];
            li.push_back(x);
        }
        for(int i=0; i<n; i++){
            cin >> li[i][1];
        }
        li.insert(li.begin(), {A, B});
        
        sort(li.begin(), li.end());
        
        vector<vector<par>> faixas = {{li[0]}};
        for(int i=1; i<li.size(); i++){
            auto& p = li[i];
            if(faixas.back().back()[0] == p[0]){
                faixas[faixas.size()-1].push_back(p);
            }
            else{
                faixas.push_back(vector<par>(1, p));
            }
        }
        
        auto dif = [&](par& a, par& b) -> int {
            return abs(a[0] - b[0]) + abs(a[1] - b[1]);
        };
        
        auto seq = [&](par& a, par& b, par& c) -> int {
            return dif(a, b) + dif(b, c);
        };
        
        //baixo 0, cima 1
        par pinf = {inf, inf};
        vector<par> dp(faixas.size(), pinf);
        dp[0][0] = seq(A, faixas[0].back(), faixas[0][0]);
        dp[0][1] = seq(A, faixas[0][0], faixas[0].back());

        for(int i=1; i<faixas.size(); i++){
            vector<par>& p = faixas[i-1];
            vector<par>& nxt = faixas[i];
            
            int a = dp[i-1][0] + seq(p[0], nxt.back(), nxt[0]); //0 0
            int b = dp[i-1][0] + seq(p[0], nxt[0], nxt.back()); //0 1
            
            int c = dp[i-1][1] + seq(p.back(), nxt.back(), nxt[0]); //1 0
            int d = dp[i-1][1] + seq(p.back(), nxt[0], nxt.back()); //1 1
            
            dp[i][0] = min(a, c);
            dp[i][1] = min(b, d);
        }
        
        int x = dp.back()[0] + dif(faixas.back()[0], B);
        int y = dp.back()[1] + dif(faixas.back().back(), B);
        
        cout << min(x,y) << "\n";
    }

    return 0;
}