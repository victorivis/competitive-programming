/* https://codeforces.com/contest/2078/problem/D */

#include <bits/stdc++.h>
using namespace std;

long long calcTotal(long long original, long long num, char c) {
	if(c=='+') {
		return num;
	}
	else {
		return original*(num-1);
	}
}

int n;
vector<pair<int, int>> num;
vector<pair<char, char>> operador;

bool mesmaOperacao(int pos){
    bool cond1 = operador[pos].first=='+' && operador[pos].second=='+';
	bool cond2 = operador[pos].first=='x' && operador[pos].second=='x' && num[pos].first == num[pos].second;
	
	return cond1 || cond2;
}

bool primeiroMelhor(int pos){
    for(int i=pos; i<n; i++){
        if(mesmaOperacao(i)==false){
            if(operador[i].first!=operador[i].second){
                return operador[i].first=='x';
            }
            else{
                return num[i].first > num[i].second;
            }
        }
    }
    return false;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
	int t;
	cin >> t;
	while(t--) {
		cin >> n;
		num={};
		operador={};

		for(int i=0; i<n; i++) {
			char a, b;
			int x, y;
			cin >> a >> x >> b >> y;

			num.push_back(pair<int, int>(x, y));
			operador.push_back(pair<char, char>(a, b));
		}

		long long num1=1, num2=1;
		
		for(int i=0; i<n; i++){
		    bool ehPrimeiro = primeiroMelhor(i+1);

		    long long total1 = calcTotal(num1, num[i].first, operador[i].first);
		    long long total2 = calcTotal(num2, num[i].second, operador[i].second);
		    long long total = total1+total2;
		    
		    if(ehPrimeiro){
		        num1+=total;
		    }
		    else{
		        num2+=total;
		    }
		}
		
		cout << (num1+num2) << "\n";
	}

	return 0;
}