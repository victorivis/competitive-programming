/*
https://www.spoj.com/problems/TDKPRIME/
*/

#include <iostream>
#include <vector>
#include <math.h>
using namespace std;
 
const int LIM = 86250000;
bool crivo[LIM];
 
const int TAM_PRIMO = 5000000;
int primos[TAM_PRIMO];
 
void preencherCrivo(){
    int cont=1;
    primos[0]=2;
    
    int i=3;
    while(cont<TAM_PRIMO){
        if(crivo[i]==0){
            primos[cont]=i;
            cont++;
            
            if(i<sqrt(LIM))
            for(int j=i*i; j<LIM; j+=i){
                crivo[j]=true;
            }
        }
        i+=2;
    }
}
 
int main(){
    preencherCrivo();
    
    int t; cin >> t;
    while(t--){
        int x; cin >> x;
        cout << primos[x-1] << "\n";
    }
 
    return 0;
} 