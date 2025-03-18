/*
https://judge.beecrowd.com/en/problems/view/1424
*/

#include <iostream>
#include <vector>
#include <map>

using namespace std;

int main(){
    int n, m, i;
    while(cin >> n >> m){
        map<int, vector<int>> lista;
        for(i=0; i<n; i++){
            int a;
            cin >> a;
            lista[a].push_back(i+1);
        }
        
        for(i=0; i<m; i++){
            int x, y;
            cin >> x >> y;
            if(lista[y].size() >= x){
                cout << lista[y][x-1] << "\n";
            }
            else{
                cout << 0 << "\n";
            }
        }
    }
    
    return 0;
}