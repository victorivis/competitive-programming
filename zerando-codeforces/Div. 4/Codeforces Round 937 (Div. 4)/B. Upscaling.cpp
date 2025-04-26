/* https://codeforces.com/contest/1950/problem/B */

#include <bits/stdc++.h>

using namespace std;

int main(){
    int x; cin >> x;
    while(x--){
        int n; cin >> n;
        for(int i=0; i<2*n; i++){
            for(int j=0; j<2*n; j++){
                bool saida;
                if((i%4 == 0 || i%4 == 1)){
                    saida=(j%4 == 0 || j%4 == 1);
                }
                else{
                    saida = (j%4 == 2 || j%4 == 3);
                }
                
                if(saida){
                    printf("#");
                }
                else{
                    printf(".");
                }
            }
            printf("\n");
        }
    }

    return 0;
}