/*
https://cses.fi/problemset/task/1637
*/

#include <bits/stdc++.h>
using namespace std;

vector<bool> vis(1e6+5, false);
 
bool digitos(int n, int presente){
    while(n>0){
        if(n%10 == presente) return true;
        n/=10;
    }
    return false;
}
 
struct par{
    int x;
    int y;
};
 
int main(){
    int n; cin >> n;
    
    queue<par> proximo;
    proximo.push({0, 0});
    
    while(true){
        int atual=proximo.front().x;
        int dist=proximo.front().y+1;
        
        if(atual==n) break;
        
        for(int k=1; k<=9; k++){
            if(vis[atual+k]==false && digitos(atual+k, k)){
                vis[atual+k]=true;
                
                proximo.push({atual+k, dist});
            }
        }
        proximo.pop();
    }
    
    cout << proximo.front().y << "\n";
    
    return 0;
}