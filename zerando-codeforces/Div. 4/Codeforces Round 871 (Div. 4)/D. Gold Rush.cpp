/* https://codeforces.com/contest/1829/problem/D */

#include <bits/stdc++.h>
using namespace std;

int main() {
    int t; cin >> t;
    
    while(t--){
    	int n, x;
    	cin >> n >> x;
    	map<int, bool> dp;
    	queue<int> fila;
    	fila.push(n);
    	
    	if(n==x) goto fim;
    	
    	while(fila.empty()==false) {
    		int atual=fila.front();
    		fila.pop();
    		
    		if(atual%3==0) {
    		    int a = atual/3, b = 2*atual/3;
    		    
    		    if(a==x || b==x) goto fim;
    		    
    		    if(a%3==0 && dp.count(a)==0){
    		        dp[a]=true;
    		        fila.push(a);
    		    }
    		    if(b%3==0 && dp.count(b)==0){
    		        dp[b]=true;
    		        fila.push(b);
    		    }
    		}
    	}
    
    	cout << "NO\n";
    	if(false) {
            fim:
    		cout << "YES\n";
    	}
    }

	return 0;
}