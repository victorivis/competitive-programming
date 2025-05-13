/*
https://cses.fi/problemset/task/1744
*/

#include <bits/stdc++.h>
using namespace std;
 
const int LIM=502;
const int INF= LIM*LIM*10;
 
int dp[LIM][LIM];
 
void preencher(){
    for(int i=0; i<LIM; i++){
        for(int j=0; j<LIM; j++){
            dp[i][j]=INF;
            if(i==0 || j==0 || i==j){
                dp[i][j]=0;
            }
            else{
                for(int k=1; k<=i; k++){
                    dp[i][j] = min(dp[i][j], 1+dp[i-k][j]+dp[k][j]);
                }
                for(int k=1; k<=j; k++){
                    dp[i][j] = min(dp[i][j], 1+dp[i][j-k]+dp[i][k]);
                }
            }
        }
    }
}
 
int main() {
	int w, h; cin >> w >> h;
	
	preencher();
	
	cout << dp[w][h] << "\n";
}