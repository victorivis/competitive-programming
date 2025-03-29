/*
A. Serval and String Theory
*/

#include <bits/stdc++.h>
using namespace std;

bool palindromo=false;

bool isLower(string s){
    int tam = s.size();
    for(int i=0; i<s.size(); i++){
        int reverso = tam-i-1;
        if(s[i]<s[reverso]){
            return true;
        }
        if(s[i]>s[reverso]){
            return false;
        }
    }
    
    palindromo=true;
    return false;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    int t; cin >> t;
    while(t--){
        int n, k; cin >> n >> k;
        string s; cin >> s;
        
        map<char, int> dict;
        for(char c: s){
            dict[c]++;
        }
        
        palindromo=false;
        bool resultado = isLower(s);
        
        if(resultado || (k>0 && dict.size()>1)){
            cout << "YES\n";
        }
        else{
            cout << "NO\n";
        }
    }
    
    return 0;
}