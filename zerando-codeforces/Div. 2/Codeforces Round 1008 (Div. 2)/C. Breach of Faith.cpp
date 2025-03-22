/* https://codeforces.com/contest/2078/problem/C */

#include <bits/stdc++.h>
using namespace std;

int n;

void printEquation(vector<long long>& l, bool reverse=false){
    for(int i=0; i<n; i++){
        if(reverse==false){
            cout << " " << l[i] << " " << l[i+n];
        }
        else{
            cout << " " << l[i+n] << " " << l[i];
        }
    }
    cout << "\n";
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
	int t;
	cin >> t;
	while(t--) {
		cin >> n;
		
		vector<long long> lista(n*2);
		map<long long, bool> dic;
		
		for(int i=0; i<n*2; i++){
		    cin >> lista[i];
		    dic[lista[i]] = true;
		}
		
		sort(lista.begin(), lista.end());
		
        long long total=0;
        
		for(int i=0; i<n; i++){
		    total -= lista[i];
		    total += lista[i+n];
		}
		
		if(dic[total]==false){
		    cout << total;
		    printEquation(lista, true);
		}
		else{
		    long long novo = total+2*lista[0];
		    cout << lista[0];
		    lista[0] = novo;
		    printEquation(lista, false);
		}
	}

	return 0;
}