/* https://codeforces.com/contest/1992/problem/E */

#include <bits/stdc++.h>
#define int long long
using namespace std;
 
int digitos(int n){
    int total=1;
    while(n>9 || n <-9){
        n/=10;
        total++;
    }
    return total;
}
 
int32_t main(){
    int teste; cin >> teste;
    while(teste--){
        int n; cin >> n;
        
        //Zera a subtracao, entao 0=0 e isso da problema
        if(n==1){
            cout << 9999 << "\n";
            for(int i=1; i<=9999; i++){
                cout << i+1 << " " << i << "\n";
            }
            continue;
        }
        
        string repeticao = to_string(n);
        int numDigitos = digitos(n);
        int coeficienteA = n - numDigitos;
        vector<pair<long long, long long>> lista;
        
        if(coeficienteA == 0){
            goto final;
        }
        
        for(double i=1; i<17; i++){
            string padrao = "";
            
            while(padrao.size() < i){
                padrao += repeticao;
            }
            padrao = padrao.substr(0, i);
            
            //cout << padrao << "\n";
            long long meuNum = stoll(padrao);
            
            double a = (meuNum - i) / coeficienteA;
            if(a == (int) a){
                double b = n * a - meuNum;
                
                if(b > min(10000ll, (long long) a*n)){
                    break;
                }
                
                //printf("a: %.0lf, b: %.0lf, meuNum: %lld, i: %.0lf\n", a, b, meuNum, i);
                
                if(b > 0 && a > 0 && a < 10000 && b < min(10000ll, (long long) a*n)){
                    lista.push_back(pair<long long, long long>(a, b));
                }
            }
        }
        
        final:
        
        printf("%ld\n", lista.size());
        for(int i=0; i<lista.size(); i++){
            printf("%lld %lld\n", lista[i].first, lista[i].second);
        }
    }
 
    return 0;
}