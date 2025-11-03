/* https://codeforces.com/contest/2162/problem/E */

#include <bits/stdc++.h>
using namespace std;

int main(){
    int t; cin >> t;
    while(t--){
        int n, k; cin >> n >> k;
        map<int, int> usado;
        set<int> nao_usado;
        
        for(int i=1; i<=n; i++){
            nao_usado.insert(i);
        }
        
        deque<int> sequencia;
        
        vector<int> lista(n);
        for(int i=0; i<n; i++){
            int x; cin >> x;
            lista[i]=x;
            nao_usado.erase(x);
        }
        
        for(int i=n-1; i>=0; i--){
            int x = lista[i];
            if(usado[x]==0){
                sequencia.push_front(x);
            }
            usado[x]++;
        }
        
        for(auto num: nao_usado){
            sequencia.push_front(num);
        }
        
        for(int i=0; i<k; i++){
            cout << sequencia[i%n] << " ";
        }
        cout << "\n";
    }
    
    return 0;
}