/* https://codeforces.com/contest/2162/problem/D */

#include <bits/stdc++.h>
using namespace std;

int main(){
    int t; cin >> t;
    while(t--){
        int n; cin >> n;
        
        
        cout << "1 1 " << n << "\n";
        cout.flush();
        int total; cin >> total;
        
        cout << "2 1 " << n << "\n";
        cout.flush();
        int extra; cin >> extra;
        
        int quant = extra - total;
        
        int l=1, r=n;
        int pos=l;
        while(l<=r){
            int mid = (l+r)/2;
            cout << "1 " << l << " " << mid << flush << endl;
            int a; cin >> a;
            
            cout << "2 " << l << " " << mid << flush << endl;
            int b; cin >> b;
            
            if(a == b){
                l=mid+1;
            }
            else{
                r=mid-1;
                pos=mid;
            }
        }
        
        cout << "! " << pos << " " << pos+quant-1 << flush << endl;
    }

    return 0;
}