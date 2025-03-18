/*
https://judge.beecrowd.com/en/runs/code/43498213
*/

#include <bits/stdc++.h>
using namespace std;

int main(){
    int n; cin >> n;
    map<string, string> d;
    
    char enter; scanf("%c", &enter);
    
    for(int i=0; i<n; i++){
        string natal, lingua;
        getline(cin, lingua);
        getline(cin, natal);
        
        d[lingua]=natal;
    }
    
    int q; cin >> q;
    scanf("%c", &enter);
    
    for(int i=1; i<=q; i++){
        string pessoa, lingua;
        getline(cin, pessoa);
        getline(cin, lingua);
        
        cout << pessoa << "\n" << d[lingua] << "\n";
        cout << "\n";
    }
    
    return 0;
}