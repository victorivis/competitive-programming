/* https://codeforces.com/gym/105327/problem/I */

#include <bits/stdc++.h>
using namespace std;

const int mod = 1e9+7;
const int LIM = 1e6+2;

int divisores[LIM] = {0};

void crivo(){
    divisores[1]=1;
    
    for(int i=2; i<LIM; i++){
        if(divisores[i]==0){
            divisores[i]=i;
            
            for(long long j = (long long) i*i; j<LIM; j+=i){
                if(divisores[j]==0)
                    divisores[j]=i;
            }
        }
    }
}

void fatorar(int n, vector<int>& fatores){
    while(n>1){
        if(fatores.empty() || divisores[n] != *(fatores.rbegin()))
            fatores.push_back(divisores[n]);
        n/=divisores[n];
    }
}

const int MAX=1e6+2;
int vis[MAX]={0};

void mostrar(int l[], int tam){
    for(int i=0; i<tam; i++){
        cout << l[tam] << " ";
    }
    cout << "\n";
}

int main(){
    crivo();
    int n; cin >>n;
    
    int x, y;
    
    long long respostas[(int) 1e5+2];
    respostas[0]=1;
    for(int i=1; i<=1e5; i++){
        respostas[i] = (respostas[i-1]<<1)%mod;
    }
    
    for(int i=0; i<n; i++){
        cin >> y;
        vector<int> fatores;
        fatorar(y, fatores);
        
        short int tam = fatores.size();
        for(int j=1; j<(1<<tam); j++){
            int marcar=1;
            for(int k=0; k<8; k++){
                if((j>>k)&1){
                    marcar*=fatores[k];
                }
            }
            vis[marcar]++;
        }
    }
    
    int q; cin >> q;
    while(q--){
        cin >> x;
        vector<int> fatores;
        fatorar(x, fatores);
        
        short int tam = fatores.size();
        
        long long total = 0;
        for(int j=1; j<(1<<tam); j++){
            int marcar=1;
            int contador=0;
            for(int k=0; k<8; k++){
                if((j>>k)&1){
                    marcar*=fatores[k];
                    contador++;
                }
            }
            
            total += (contador%2==1 ? vis[marcar] : -vis[marcar]);
        }
        if(total<0){
            return 1;
        }
        
        cout << respostas[n-total] << "\n";
    }
    
    
    return 0;
}