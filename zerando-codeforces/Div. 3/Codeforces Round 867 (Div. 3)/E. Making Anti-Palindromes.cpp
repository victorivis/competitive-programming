/* https://codeforces.com/contest/1921/problem/E */

#include <bits/stdc++.h>
using namespace std;
 
int main(){
    int t; cin >> t;
    while(t--){
        int n; cin >> n;
        string s; cin >> s;
        
        if(s.size()%2==1){
            cout << "-1\n";
        }
        else{
            vector<int> letras(26, 0);
            for(char c: s){
                letras[c-'a']++;
            }
            
            int maior=0;
            for(int i: letras){
                maior = max(maior, i);
            }
            
            int tam = s.size();
            if(maior>tam-maior){
                cout << "-1\n";
            }
            else{
                int numPares=0;
                
                vector<int> pares(26, 0);
                int maiorPar = 0;
                for(int i=0; i<tam/2; i++){
                    if(s[i] == s[tam-i-1]){
                        int pos = s[i]-'a';
                        pares[pos]++;
                        numPares++;
                        maiorPar = max(maiorPar, pares[pos]); 
                    }
                }
                
                int total = (maiorPar >= numPares-maiorPar ? maiorPar : (numPares+1)/2 );
                cout << total << "\n";
            }
        }
    }
 
    return 0;
}