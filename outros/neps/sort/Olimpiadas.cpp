/*
https://neps.academy/br/exercise/243
*/

#include <bits/stdc++.h>
using namespace std;

struct medal{
    int id;
    int gold;
    int silver;
    int bronze;
};

bool compare(medal& a, medal& b){
    if(a.gold != b.gold) return a.gold>b.gold;
    if(a.silver != b.silver) return a.silver>b.silver;
    if(a.bronze != b.bronze) return a.bronze>b.bronze;
    return a.id < b.id;
}

int main(){
    int n, m; cin >> n >> m;
    vector<medal> countries(n);
    
    for(int i=0; i<n; i++){
        countries[i] = {i+1,0,0,0};
    }
    
    for(int i=0; i<m; i++){
        int x, y, z; cin >> x >> y >> z;
        countries[x-1].gold++;
        countries[y-1].silver++;
        countries[z-1].bronze++;
    }
    
    sort(countries.begin(), countries.end(), compare);
    
    for(int i=0; i<countries.size(); i++){
        cout << countries[i].id << " ";
    }
    cout << "\n";

    return 0;
}