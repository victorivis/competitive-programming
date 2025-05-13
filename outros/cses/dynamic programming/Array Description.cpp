/*
https://cses.fi/problemset/task/1746/
*/

#include <bits/stdc++.h>
using namespace std;
 
const int modulo = 1e9+7;
 
int main() {
	int n, m;
	cin >> n >> m;
	vector<int> lista(n);
	for(int i=0; i<n; i++) {
		cin >> lista[i];
	}
 
	vector<vector<int>> dp(n+2, vector<int>(m+2, 0));
	
	if(lista[0]==0) {
		dp[0] = vector<int>(m+2, 1);
		dp[0][0] = 0;
		dp[0][m+1] = 0;
	}
	else {
		dp[0][lista[0]]=1;
	}
	
	for(int i=1; i<n; i++) {
		if(lista[i]==0) {
			for(int j=1; j<=m; j++) {
				dp[i][j] = ((long long) dp[i-1][j-1]+dp[i-1][j]+dp[i-1][j+1])%modulo;
			}
		}
		else {
			int pos=lista[i];
			dp[i][pos] = ((long long) dp[i-1][pos-1]+dp[i-1][pos]+dp[i-1][pos+1])%modulo;
		}
	}
	
	long long total=0;
	for(int i=1; i<=m; i++) {
		total = (total + dp[n-1][i])%modulo;
	}
	
	cout << total << "\n";
}