/* https://codeforces.com/contest/1703/problem/F */

#include <bits/stdc++.h>
using namespace std;
 
#define int long long
 
vector<int> criarFenwickTree(vector<int>& lista){
    vector<int> arvore = lista;
 
    for(int i=1; i<lista.size(); i++){
        int pai = i + (i & -i);
        if(pai < lista.size()){
            arvore[pai] = arvore[pai] + arvore[i];
        }
    }
    return arvore;
}
 
int invervaloFenwickTree(vector<int>& lista, int i){
    int soma=0;
    while(i > 0){
        soma+=lista[i];
        i -= i & -i;
    }
    return soma;
}
 
//Retorna so o valor
int posicaoFenwickTree(vector<int>& lista, int i){
    return invervaloFenwickTree(lista, i) - invervaloFenwickTree(lista, i-1);
}
 
void modificarFenwickTree(vector<int>& lista, int i, int valorAdicionado){
    while(i < lista.size()){
        lista[i] += valorAdicionado;
        i += i & -i;
    }
}
 
void normalizar(vector<int>& lista){
    int contador=1;
    map<int, int> endereco;
    vector<int> copia = lista;
    for(int i=0; i<copia.size(); i++){
        if(endereco.count(copia[i])==0){
            endereco[copia[i]]=contador++;
        }
    }
    
    vector<int> fenwickMaior(lista.size()+5, 0);
    
    vector<int> maiores(lista.size(), 0);
    vector<bool> vetorValidos(lista.size(), false);
 
    for(int i=0; i<lista.size(); i++){
        int atual = lista[i];
 
        if(atual < i+1){
            vetorValidos[i] = true;
            maiores[i]= invervaloFenwickTree(fenwickMaior, atual-1);
            modificarFenwickTree(fenwickMaior, i+1, 1);
        }
    }
 
    long long total=0;
    for(int i : maiores){
        total+=i;
    }
 
    cout << total << "\n";
}
 
int32_t main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
 
    int t; cin >> t;
    while(t--){
        int n; cin >> n;
        vector<int> lista(n);
        for(int i=0; i<n; i++){
            cin >> lista[i];
        }
        
        normalizar(lista);
    }
 
    return 0;
}