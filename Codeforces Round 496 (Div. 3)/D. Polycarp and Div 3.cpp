/* https://codeforces.com/contest/1005/problem/D */

#include <bits/stdc++.h>
using namespace std;

int main(){
    string s; cin >> s;
    
    int resto=0;
    int total=0;
    int contador=0;
    for(int i=0; i<s.size(); i++){
        int atual = (s[i] - '0')%3;
        resto +=atual;
        contador++;
        if(atual==0 || resto%3==0 || contador%3==0){
            total++;
            resto=0;
            contador=0;
        }
    }
    cout << total << "\n";
    
    return 0;
}