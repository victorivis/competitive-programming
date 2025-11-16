/* https://codeforces.com/contest/450/problem/B */
// existe um jeito mais facil considerando os 6 primeiros resultados e fazendo pos mod 6

#include <bits/stdc++.h>
using namespace std;

#define int long long
#define vv vector<vector<int>>

int modulo = 1e9+7;

vv mult(vv& a, vv& b){
    vv c(a.size(), vector<int>(b[0].size()));
    
    for(int i=0; i<a.size(); i++){
        for(int j=0; j<b[0].size(); j++){
            int total=0;
            
            for(int k=0; k<b.size(); k++){
                total = total%modulo + ((a[i][k]*b[k][j])%modulo+modulo)%modulo;
            }
            
            c[i][j] = (total%modulo+modulo)%modulo;
        }
    }
    return c;
}

vv neutra = {{1, 0}, {0, 1}};

vv expon(vv& a, int pot){
    if(pot == 0){
        return neutra;
    }
    if(pot == 1){
        return a;
    }
    
    vv resultado = pot%2 == 0 ? neutra : a;
    vv metade = expon(a, pot/2);
    
    vv temp = mult(resultado, metade);
    
    return mult(temp, metade);
}

void mostrar(vv& matriz){
    for(int i=0; i<matriz.size(); i++){
        for(int num: matriz[i]){
            cout << num << " ";
        }
        cout << "\n";
    }
}

int32_t main(){
    int f1, f2; cin >> f1 >> f2;
    f1 = (f1+modulo)%modulo; f2 = (f2+modulo)%modulo;
    int pos; cin >> pos;
    
    vv regra = {{0, 1}, {-1, 1}};
    vv atual = {{f1}, {f2}};
    
    if(pos == 1){
        cout << f1 << "\n";
    }
    else if(pos == 2){
        cout << f2 << "\n";
    }
    else{
        vv graal = expon(regra, pos-2);
        vv temp = mult(graal, atual);
        cout << temp[1][0];
        cout << "\n";
    }    

    return 0;
}