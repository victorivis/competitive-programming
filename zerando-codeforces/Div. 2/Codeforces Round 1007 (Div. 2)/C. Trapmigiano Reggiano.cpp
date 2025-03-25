/* https://codeforces.com/contest/2071/problem/C */

#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> graph;
vector<int> backtrack;
vector<bool> vis;

void findpath(int i){
    vis[i]=true;
    
    for(int j=0; j<graph[i].size(); j++){
        int curr = graph[i][j];
        
        if(vis[curr]==false){
            findpath(curr);
            backtrack[curr]=i;
        }
    }
}

void dfs(int i){
    vis[i]=true;
    
    for(int j=0; j<graph[i].size(); j++){
        int curr = graph[i][j];
        
        if(vis[curr]==false){
            dfs(curr);
            cout << curr << " ";
        }
    }
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    int t; cin >> t;
    while(t--){
        int n, start, end; cin >> n >> start >> end;
        
        graph.assign(n+1, vector<int>());
        backtrack.assign(n+1, -1);
        vis.assign(n+1, false);
        
        for(int i=0; i<n-1; i++){
            int x, y; cin >> x >> y;
            graph[x].push_back(y);
            graph[y].push_back(x);
        }
        
        findpath(start);
        vis.assign(n+1, false);
        
        stack<int> mainNode;
        int lastNode=end;
        while(lastNode!=-1){
            vis[lastNode]=true;
            mainNode.push(lastNode);
            lastNode = backtrack[lastNode];
        }
        
        while(mainNode.empty()==false){
            int curr = mainNode.top();
            
            dfs(curr);
            cout << curr << " ";
            
            mainNode.pop();
        }
        cout << "\n";
    }
    
    return 0;
}