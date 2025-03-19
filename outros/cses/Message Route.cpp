/*
https://cses.fi/problemset/result/12380150/
*/

#include <bits/stdc++.h>
using namespace std;
 
int n, m;
 
vector<vector<int>> grafo;
vector<bool> vis;
vector<int> previous;
 
void mostrar(vector<vector<int>>& matriz){
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            cout << matriz[i][j];
        }
        cout << "\n";
    }
}
 
int main(){
    cin >> n >> m;
    
    previous.assign(n+1, -1);
    vis.assign(n+1, false);
    grafo.assign(n+1, vector<int>());
    
    queue<pair<int, int>> computer;
    
    for(int i=0; i<m; i++){
        int x, y; cin >> x >> y;
        grafo[x].push_back(y);
        grafo[y].push_back(x);
    }
    
    computer.push(pair<int, int>(1, 0));
    vis[1]=true;
    
    while(computer.empty()==false){
        int x = computer.front().first;
        int d = computer.front().second + 1;
        
        for(int i=0; i<grafo[x].size(); i++){
            int curr = grafo[x][i];
            if(vis[curr]==false){
                previous[curr]=x;
                computer.push(pair<int, int>(curr, d));
                vis[curr]=true;
            }
        }
        
        computer.pop();
    }
    
    if(vis[n]){
        int last = n;
        stack<int> order;
        int total=0;
        while(last!=-1){
            total++;
            order.push(last);
            last = previous[last];
        }
        
        cout << total << "\n";
        while(order.empty()==false){
            cout << order.top() << " ";
            order.pop();
        }
        cout << "\n";
    }
    else{
        cout << "IMPOSSIBLE\n";
    }
    
    return 0;
}
