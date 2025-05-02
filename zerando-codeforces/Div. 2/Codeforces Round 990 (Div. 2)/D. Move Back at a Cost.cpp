/* https://codeforces.com/contest/2047/problem/D */

#include <bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    int t; cin >> t;
    while(t--){
        int n; cin >> n;
        vector<int> lista(n);
        vector<pair<int, int>> ordenar(n);
        
        for(int i=0; i<n; i++){
            cin >> lista[i];
            
            ordenar[i] = pair<int, int>(lista[i], i);
        }
        
        sort(ordenar.begin(), ordenar.end());
        
        vector<int> resposta;
        vector<int> extras;
        
        int maiorDesordem=-1;
        int i;
        for(i=0; i<n; i++){
            int posAtual = ordenar[i].second;
            int numAtual = ordenar[i].first;
            
            if(maiorDesordem<posAtual){
                resposta.push_back(numAtual);
                maiorDesordem = posAtual;
            }
            else{
                extras.push_back(numAtual+1);

                int contador=1;
                while(i+contador<n && ordenar[i+contador].first<=numAtual+1){
                    int novaPos = ordenar[i+contador].second;
                    int novoNum = ordenar[i+contador].first;
                    
                    if(maiorDesordem < novaPos){
                        resposta.push_back(novoNum);
                        maiorDesordem = novaPos;
                    }
                    else{
                        extras.push_back(novoNum+1);
                    }
                    contador++;
                }
                
                i += contador;
                break;
            }
        }
        
        //Adicionando as baguncas
        for(int k: extras){
            resposta.push_back(k);
        }
        
        while(i<n){
            resposta.push_back(ordenar[i].first+1);
            i++;
        }
        
        //Finalmente a resposta
        for(int k: resposta){
            cout << k << " ";
        }
        cout << "\n";
    }

    return 0;
}