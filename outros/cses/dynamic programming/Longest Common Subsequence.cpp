/*
https://cses.fi/problemset/task/3403/
*/

#include <bits/stdc++.h>
using namespace std;
 
int main() {
	int n; cin >> n;
	int m; cin >> m;
	
	vector<int> l1(n);
	for(int& i: l1){
	    cin >> i;
	}
	
	vector<int> l2(m);
	for(int& i: l2){
	    cin >> i;
	}
	
	vector<vector<int>> dp(n+1, vector<int>(m+1, 0));

	for(int i=1; i<=n; i++){	    
	    for(int j=1; j<=m; j++){
	        dp[i][j] = max(dp[i-1][j-1] + (l1[i-1]==l2[j-1]), dp[i][j]);
	        dp[i][j] = max(dp[i][j], dp[i-1][j]);
	        dp[i][j] = max(dp[i][j], dp[i][j-1]);
	    }
	}
	
	int x=m;
	
	stack<int> sequencia;
	
	int i=n, j=m;
	int valor=dp[i][j];
	
	while(valor>0){
	    while(dp[i-1][j]>=valor){
	        i--;
	    }
	    
	    while(dp[i][j-1]>=valor){
	        j--;
	    }
	    
	    i--;
	    j--;
	    valor--;
	    
	    sequencia.push(l1[i]);
	}
	
	cout << dp[n][m] << "\n";
	while(sequencia.empty()==false){
	    cout << sequencia.top() << " ";
	    sequencia.pop();
	}
	cout << "\n";
}
