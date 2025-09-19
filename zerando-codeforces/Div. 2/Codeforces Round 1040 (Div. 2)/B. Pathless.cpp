/* https://codeforces.com/contest/2130/problem/B */

#include <bits/stdc++.h>
using namespace std;

const int LIM = 3;

int main(){
    int t; cin >> t;
    while(t--){
        int n, s; cin >> n >> s;
        vector<int> lista(n);
        
        vector<int> quantidades(LIM, 0);
        long long total = 0;
        
        for(int i=0; i<n; i++){
            cin >> lista[i];
            total+=lista[i];
            quantidades[lista[i]%LIM] += 1;
        }
        
        if(s<total || s==total+1){
            vector<int> sequencia = {0, 2, 1};
            for(int num: sequencia){
                for(int i=0; i<quantidades[num]; i++){
                    cout << num << " ";
                }
            }
            cout << "\n";
        }
        else{
            cout << "-1\n";
        }
    }

    return 0;
}