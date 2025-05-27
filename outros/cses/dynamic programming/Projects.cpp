/*
https://cses.fi/problemset/result/13073712/
*/

#include <bits/stdc++.h>
using namespace std;
 
#define int long long
 
struct trio{
    int l;
    int r;
    int valor;
};
 
bool comparar(trio& A, trio& B){
    return A.r < B.r;
}
 
int32_t main(){
    int n; cin >> n;
    vector<trio> lista(n);
    
    vector<int> preCompressao(2*n+1, 0);
    
    for(int i=0; i<n; i++){
        cin >> lista[i].l >> lista[i].r >> lista[i].valor;
        preCompressao[2*i+1]=lista[i].l;
        preCompressao[2*i+2]=lista[i].r;
    }
    
    sort(lista.begin(), lista.end(), comparar);
    sort(preCompressao.begin(), preCompressao.end());
    
    map<int, int> compressao;
    
    int coordenada=1;
    for(int i=1; i<2*n+1; i++){
        if(preCompressao[i]!=preCompressao[i-1]){
            compressao[preCompressao[i]]=coordenada++;
        }
    }
    
    vector<long long> dp(coordenada, 0);
    
    int pont=0;
    
    for(int i=1; i<coordenada; i++){
        dp[i] = max(dp[i-1], dp[i]);
        
        while(pont<n && compressao[lista[pont].r] == i){
            long long valor = dp[compressao[lista[pont].l]-1] + lista[pont].valor;
            
            dp[i] = max(dp[i], valor);
            
            pont++;
        }
    }
    
    cout << dp.back() << "\n";
 
    return 0;
}