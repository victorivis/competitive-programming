/*
https://codeforces.com/contest/2033/problem/A
*/

#include <stdio.h>

int main(){
    int teste; scanf("%d", &teste);
    while(teste--){
        int n; scanf("%d", &n);
        n%2==1 ? printf("Kosuke\n") : printf("Sakurako\n");
    }

    return 0;
}