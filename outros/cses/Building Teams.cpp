/*
https://cses.fi/problemset/task/1668/
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
    
    vector<int> team(n+1, 0);
    
    
    
    for(int i=0; i<m; i++){
        int x, y; cin >> x >> y;
        grafo[x].push_back(y);
        grafo[y].push_back(x);
    }
    
    bool possible=true;
    
    for(int i=1; i<=n; i++){
        if(vis[i]==false){            
            queue<pair<int, int>> people;
            people.push(pair<int, int>(i, 1));
            team[i]=1;
            vis[i]=true;
            
            while(people.empty()==false){
                int x = people.front().first;
                int t = people.front().second==1 ? 2 : 1;
                
                for(int i=0; i<grafo[x].size(); i++){
                    int curr = grafo[x][i];
                    
                    if(vis[curr]==false){
                        people.push(pair<int, int>(curr, t));
                        vis[curr]=true;
                    }
                    
                    if(team[curr]==0){
                        team[curr]=t;
                    }
                    else if(team[curr]!=t){
                        possible=false;
                        goto end;
                    }
                }
                
                people.pop();
            }
        }
    }
    
    end:
    if(possible){
        for(int i=1; i<team.size(); i++){
            cout << team[i] << " ";
        }
        cout << "\n";
    }
    else{
        cout << "IMPOSSIBLE\n";
    }
    
    return 0;
}