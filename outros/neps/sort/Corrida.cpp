/*
https://neps.academy/br/exercise/338
*/

#include <bits/stdc++.h>
using namespace std;

struct runner {
    int id;
    int total_time;
};

bool compare(runner& a, runner& b){
    return a.total_time < b.total_time;
}

int main(){
    int n, m; cin >> n >> m;
    
    vector <runner> allRunners(n);
    
    for(int i=0; i<n; i++){
        int total_time=0;
        for(int i=0; i<m; i++){
            int x; cin >> x;
            total_time+=x;
        }
        
        allRunners[i]={i+1,total_time};
    }
    
    sort(allRunners.begin(), allRunners.end(), compare);
    
    for(int i=0; i<3; i++){
        cout << allRunners[i].id << "\n";
    }

    return 0;
}