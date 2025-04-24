/* https://codeforces.com/contest/1703/problem/A */

#include <bits/stdc++.h>
using namespace std;

int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    
    int t; cin >> t;
    
    for(int i=0; i<t; i++){
        string l; cin >> l;
        if((l[0]=='y'||l[0]=='Y')&&(l[1]=='e'||l[1]=='E')&&(l[2]=='s'||l[2]=='S')){
            cout << "YES\n";
        }
        else{
            cout << "NO\n";
        }
    }

    return 0;
}