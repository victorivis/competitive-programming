/* https://codeforces.com/contest/1950/problem/A */

#include <bits/stdc++.h>

using namespace std;

int main(){
    int n; cin >> n;
    while(n--){
        int a, b, c; cin >> a >> b >> c;
        if(a<b && b<c){
            printf("STAIR\n");
        }
        else if(a<b && b>c){
            printf("PEAK\n");
        }
        else{
            printf("NONE\n");
        }
    }

    return 0;
}