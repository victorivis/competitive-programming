/*
https://codeforces.com/contest/2085/problem/C
*/

#include <bits/stdc++.h>
using namespace std;

const int limite = 61;

void mostrar(int n){
    for(int i=31; i>=0; i--){
        int bit = (n>>i)&1;
        cout << bit;
    }
    cout << "\n";
}

int posZero(long long num, int pos){
    while(pos < limite){
        int bit = (num>>pos)&1;
        
        if(bit==0){            
            return pos;
        }
        pos++;
    }

    return -1;
}

long long percorrer(long long x, long long y, int pos){
    long long total=0;
    
    int remix=-1;
    
    if(x==y) return -1;
    
    for(int i=pos; i<limite; i++){
        int a = (x>>i) & 1; 
        int b = (y>>i) & 1;
        
        if(a+b==1){
            remix=i;
        }
        
        int both = a&b;
        
        if(both == 1){            
            long long somar;
            
            int zeroX = posZero(x, i);
            int zeroY = posZero(y, i);
            
            if(remix!=-1 && zeroX==zeroY){                
                somar = (1ll<<remix);
                i = remix;
            }
            else{
                somar = (1ll<<i);
            }
            
            x+=somar;
            y+=somar;
            total+=somar;
        }
    }
    long long intercecao = (x & y);
    
    if(intercecao!=0){
        return -1;
    }
    else{
        return total;
    }
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    int t; cin >> t;
    
    while(t--){
        long long x, y; cin >> x >> y;
        
        long long bX=x;
        long long bY=y;
        
        long long resposta=percorrer(bX, bY, 0);
        cout << resposta << "\n";
    }
    
    return 0;
}