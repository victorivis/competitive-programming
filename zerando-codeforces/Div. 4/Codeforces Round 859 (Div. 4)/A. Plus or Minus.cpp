/* https://codeforces.com/contest/1807/problem/A */

#include <stdio.h>

int main(){
    int n; scanf("%d", &n);
    while(n--){
        int a, b, c; scanf("%d%d%d", &a, &b, &c);
        if(a+b==c){
            printf("+\n");
        }
        else{
            printf("-\n");
        }
    }

    return 0;
}