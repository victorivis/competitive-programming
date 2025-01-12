/* https://github.com/victorivis/zerando-codeforces */

#include <bits/stdc++.h>
using namespace std;

vector<int> parent;

void make_set(int size){
    parent.resize(size);
    
    for(int i=0; i<parent.size(); i++){
        parent[i]=i;
    }
}

int find_set(int v) {
    if (v == parent[v])
        return v;
    return parent[v] = find_set(parent[v]);
}

void union_sets(int a, int b) {
    a = find_set(a);
    b = find_set(b);
    if (a != b)
        parent[b] = a;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    int n, q; cin >> n >> q;
    vector<int> lista(n+2);
    vector<int> numToPos(n+2);
    make_set(n+2);
    
    for(int i=1; i<=n; i++){
        cin >> lista[i];
        numToPos[lista[i]]=i;
    }
    
    vector<vector<int>> conjuntos(n+2);
    
    for(int i=0; i<q; i++){
        int x, y; cin >> x >> y;
        
        union_sets(lista[x], lista[y]);
    }
    
    for(int i=1; i<=n; i++){
        int pai = find_set(i);
        //cout << "(" << i << ", " << pai << ") ";
        
        conjuntos[pai].push_back(i);
    }
    //cout << "\n";
    
    for(int i=1; i<=n; i++){
        if(conjuntos[i].size()>1){
            vector<int> posicoes;
            for(int j=0; j<conjuntos[i].size(); j++){
                int pos = numToPos[conjuntos[i][j]];
                posicoes.push_back(pos);
            }
            
            sort(posicoes.begin(), posicoes.end());
            sort(conjuntos[i].begin(), conjuntos[i].end(), greater<int>());
            
            for(int j=0; j<conjuntos[i].size(); j++){
                lista[posicoes[j]] = conjuntos[i][j];
            }
        }
    }
    
    for(int i=1; i<=n; i++){
        cout << lista[i] << " ";
    }
    cout << "\n";

    return 0;
}