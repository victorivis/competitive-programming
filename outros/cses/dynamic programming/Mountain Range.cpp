/*
https://cses.fi/problemset/task/3314/
*/

#include <bits/stdc++.h>
using namespace std;

const int K=18;
const int MAXN=2e5+1;

int st[K + 1][MAXN];
int lg[MAXN+1];
map<pair<int, int>, int> dp;

vector<int> lista;
map<int, vector<int>> posicoes;

int maxIntervalo(int L, int R){
    int i = lg[R - L + 1];
    int maximo = max(st[i][L], st[i][R - (1 << i) + 1]);
    return maximo;
}

int glide(int l, int r){
    if(l>r) return 0;
    if(l==r) return 1;
    if(r-l==1){
        return 1 + (lista[r]!=lista[l]);
    }
    
    pair<int, int> limites(l, r);
    
    int maior=0;
    if(dp.count(limites)==0){
        int num = maxIntervalo(l, r);
        vector<int>& listaAtual = posicoes[num];
        auto atual = lower_bound(listaAtual.begin(), listaAtual.end(), l);

        vector<int> listaPosicoes = {l-1};
        while(atual != listaAtual.end() && *atual <= r){
            listaPosicoes.push_back(*atual);
            atual = next(atual);
        }
        listaPosicoes.push_back(r+1);        
        
        for(int i=0; i<listaPosicoes.size()-1; i++){
            int proximoIntervalo = 1+glide(listaPosicoes[i]+1, listaPosicoes[i+1]-1);
            maior = max(maior, proximoIntervalo);
        }

        dp[limites] = maior;
    }
    return dp[limites];
}

int main(){
    lg[1] = 0;
    for (int i = 2; i <= MAXN; i++)
        lg[i] = lg[i/2] + 1;
    
    int N; cin >> N;
    lista.assign(N, 0);
    
    for(int i=0; i<N; i++){
        cin >> lista[i];
        posicoes[lista[i]].push_back(i);
    }
    
    copy(lista.begin(), lista.end(), st[0]);

    for (int i = 1; i <= K; i++)
        for (int j = 0; j + (1 << i) <= N; j++)
            st[i][j] = max(st[i - 1][j], st[i - 1][j + (1 << (i - 1))]);
    
    int resultado = glide(0, N-1);

    cout << resultado << "\n";

    return 0;
}