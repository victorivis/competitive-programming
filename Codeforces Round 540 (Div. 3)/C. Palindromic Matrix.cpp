/* https://codeforces.com/contest/1118/problem/C */

#include <bits/stdc++.h>
using namespace std;

void mostrar(vector<vector<int>>& matriz){
    for(int i=0; i<matriz.size(); i++){
        for(int j=0; j<matriz[i].size(); j++){
            cout << matriz[i][j] << " ";
        }
        cout << "\n";
    }
}

int main(){
    //ios_base::sync_with_stdio(0);
    //cin.tie(0);
    
    int n; cin >> n;
    
    map<int, int> d;
    for(int i=0; i<n*n; i++){
        int x; cin >> x;
        d[x]++;
    }
    
    int um = (n%2==1 ? 1 : 0);
    int dois = (n%2==1 ? (n/2)*2 : 0);
    
    vector<vector<int>> matriz(n, vector<int>(n));
    
    int meio=n/2;
    
    for(auto& par: d){
        if(par.second%2==1){
            if(um>0){
                um--;
                par.second--;
                matriz[meio][meio]=par.first;
            }
            else{
                cout << "NO\n";
                return 0;
            }
        }
        
        if(par.second%4==2){
            if(dois>0){
                int j = (dois-1)/2;
                if(dois%2==0){
                    matriz[meio][j] = par.first;
                    matriz[meio][n-j-1] = par.first;
                }
                else{
                    matriz[j][meio] = par.first;
                    matriz[n-j-1][meio] = par.first;
                }
                
                dois--;
                par.second-=2;
            }
            else{
                cout << "NO\n";
                return 0;
            }
        }
    }
    
    auto par = d.begin();
    while(par!=d.end() && par->second<=0){
        par = next(par);
    }
    
    
    
    if(dois%2!=0){
        cout << "NO\n";
        return 0;
    }
    else{
        
        while(dois!=0){
            int j = (dois-1)/2;
            
            matriz[meio][j] = par->first;
            matriz[meio][n-j-1] = par->first;
            matriz[j][meio] = par->first;
            matriz[n-j-1][meio] = par->first;
            
            par->second-=4;
            dois-=2;
            while(par!=d.end() && par->second<=0){
                par = next(par);
            }
        }
    }
    
    
    
    for(int i=0; i<meio; i++){
        for(int j=0; j<meio; j++){
            int cI = n-i-1;
            int cJ = n-j-1;
            
            par->second -= 4;
            
            matriz[i][j] = par->first;
            matriz[cI][j] = par->first;
            matriz[i][cJ] = par->first;
            matriz[cI][cJ] = par->first;
            
            while(par!=d.end() && par->second<=0){
                par = next(par);
            }
        }
    }
    
    cout << "YES\n";
    mostrar(matriz);

    return 0;
}