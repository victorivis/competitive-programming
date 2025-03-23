/* https://codeforces.com/contest/2071/problem/B */

#include <bits/stdc++.h>
using namespace std;

const int limit = 5e5+2;
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    long long total=0;
    
    unordered_map<int, bool> invalid;
    
    for(int i=1; i<=limit; i++){
        total+=i;
        
        double raiz = sqrt(total);
        if(raiz == (long long) raiz){
            invalid[i]=true;
        }
    }
    
    int t; cin >> t;
    
    while(t--){
        int n; cin >> n;
        
        if(invalid.count(n)!=0){
            cout << "-1\n";
        }
        else{
            for(int i=0; i<n; i++){
                if(invalid.count(i+1)==0){
                   cout << i+1 << " ";
                }
                else{
                    cout << i+2 << " ";
                    cout << i+1 << " ";
                    
                    i++;
                }
            }
            cout << "\n";
        }
    }

    return 0;
}