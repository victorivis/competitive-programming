/* https://codeforces.com/contest/1950/problem/C */

#include <bits/stdc++.h>

using namespace std;

int main(){
    int x; cin >> x;
    while(x--){
        int a, b;
        char dois_pontos;
        scanf("%d%c%d", &a, &dois_pontos, &b);
        
        bool PM=false;
        if(a/12){
            a-=12;
            PM=true;
        }
        if(a==0) a=12;
        
        printf("%02d:%02d ", a, b);
        if(PM){
            printf("PM\n");
        }
        else{
            printf("AM\n");
        }
    }
    
    return 0;
}