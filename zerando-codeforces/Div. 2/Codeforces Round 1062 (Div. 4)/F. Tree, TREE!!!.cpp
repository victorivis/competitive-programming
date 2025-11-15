/* https://codeforces.com/contest/2167/problem/F */

#include <bits/stdc++.h>
using namespace std;

#define int long long
#define ll long long
#define par pair<ll, ll>

int32_t main(){
    int t; cin >> t;
    while(t--){
        int n, k; cin >> n >> k;
        vector<vector<int>> grafo(n+1);
        for(int i=0; i<n-1; i++){
            int x, y; cin >> x >> y;
            grafo[x].push_back(y);
            grafo[y].push_back(x);
        }
        
        map<par, int> dict;
        vector<int> preenchidos(n+1, 0);
        
        int folha=-1;
        for(int i=1; i<=n; i++){
            if(grafo[i].size() == 1){
                int pr = grafo[i][0];
                dict[par(i, pr)] = n-1;
                dict[par(pr, i)] = 1;
                preenchidos[i]++;
                preenchidos[pr]++;
                folha = i;
            }
        }
        
        auto preenche = [&](auto& preenche, int pos, int ant) -> void{
            int somatorio=0;
            int falta=-1;
            
            for(int pr: grafo[pos]){
                if(pr != ant){
                    preenche(preenche, pr, pos);
                }
                int temp = dict[par(pos, pr)];
                somatorio += temp;
                
                if(temp == 0){
                    falta = pr;
                }
            }
            
            if(preenchidos[pos] == grafo[pos].size()-1){
                dict[par(pos, falta)] = n-somatorio-1;
                dict[par(falta, pos)] = somatorio+1;
                preenchidos[pos]++;
                preenchidos[falta]++;
            }
        };
        
        preenche(preenche, folha, -1);
        
        int total=n;
        for(int i=1; i<=n; i++){
            for(int pr: grafo[i]){
                int temp = dict[par(pr, i)];
                if(temp>=k){
                    total += n-temp;
                }
            }
        }
        cout << total << "\n";
    }

    return 0;
}