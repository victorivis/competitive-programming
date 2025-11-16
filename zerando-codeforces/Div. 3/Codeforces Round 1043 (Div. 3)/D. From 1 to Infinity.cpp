/* https://codeforces.com/problemset/problem/2132/D */

#include <bits/stdc++.h>
using namespace std;

#define int long long

int tr(int n){
    return n * (n+1) / 2;
}

int32_t main(){
    int quant = 14;
    
    vector<int> dp = {0};

    int pot = 1;
    for(int i=1; i<=quant; i++){
        int a = pot * tr(9) + 9 * dp[i-1];
        dp.push_back(a);
        pot*=10;
    }
    
    int t; cin >> t;
    while(t--){
        int k; cin >> k; int temp = k;
        int n = 0;
        int pos=1;
        int quant=9;
        while(pos * quant <= temp){
            n += quant;
            temp -= pos*quant;
            pos++;
            quant *= 10;
        }
        int extra = temp%pos;
        n += temp/pos;
        
        vector<int> l; temp = n+1;
        while(temp){
            l.push_back(temp%10);
            temp/=10;
        }
        
        pot = 1;
        int total=0;
        for(int i=0; i<l.size(); i++, pot*=10){
            int num = l[i];
            total += (n+1) / (pot*10) * tr(9) * pot;
            total += tr(num-1) * pot;
            if(i) total += num * ((n) % (pot*10) - num * pot + 1);
        }
        while(extra--){
            total += l.back();
            l.pop_back();
        }
        cout << total << "\n";
    }

    return 0;
}