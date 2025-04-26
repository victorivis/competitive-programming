/* https://codeforces.com/contest/1950/problem/E */

#include <bits/stdc++.h>
using namespace std;

void fatorar(int n, vector<int>& saida){
    for(int i=1; i<=sqrt(n); i++){
        if(n%i==0){
            saida.push_back(i);
            if(n/i != i) saida.push_back(n/i);
        }
    }
    
    sort(saida.begin(), saida.end());
}

int contar_diferentes(string& s, int n){

    string a = s.substr(0, n);
    string b = s.substr(s.size()-n, n);
    
    int contA=0;
    int contB=0;
    
    for(int i=0; i<s.size(); i+=n){
        for(int j=0; j<n; j++){
            if(a[j] != s[i+j]) contA++;
            if(b[j] != s[i+j]) contB++;
        }
    }
    
    return min(contA, contB);
}

int main(){
    int t; cin >> t;
    while(t--){
        int n; cin >> n;
        string s; cin >> s;

        vector<int> fatores;
        fatorar(n, fatores);
        
        int l=0, r=fatores.size()-1;
        int ultimo = n;
        
        for(int i=0; i<fatores.size()-1; i++){
            if(contar_diferentes(s, fatores[i])<=1){
                ultimo=fatores[i];
                break;
            }
        }
        
        cout << ultimo << "\n";
    }
    
    return 0;
}