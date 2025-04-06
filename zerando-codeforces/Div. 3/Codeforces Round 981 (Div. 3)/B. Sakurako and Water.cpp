/*
https://codeforces.com/contest/2033/problem/B
*/

#include <bits/stdc++.h>
using namespace std;

#define teste int teste; cin >> teste;while(teste--)
#define rapido ios_base::sync_with_stdio(false);cin.tie(NULL);

void mostrar(vector<int>& lista){
    for(int i=0; i<lista.size(); i++){
        printf("%d ", lista[i]);
    }
    printf("\n");
}

void mostrar(vector<vector<int>>& lista){
    for(int i=0; i<lista.size(); i++){
        for(int j=0; j<lista[i].size(); j++){
            cout << lista[i][j] << " ";
        }
    }
    printf("\n");
}

int main(){
    teste{
        int n; cin >> n;
        vector<vector<int>> matriz(n, vector<int>(n));
        
        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){
                cin >> matriz[i][j];
            }
        }
        
        int total=0;
        for(int i=-n+1; i<n; i++){
            int x = max(i, 0);
            int menor=0;
            for(int j=x; j < x + n-abs(i); j++){
                //cout << "(" << j << ", " << j<< ") ";
                //cout << matriz[j][j-i] << " ";
                menor = min(menor, matriz[j][j-i]);
            }
            //cout << "\n";
            total-=menor;
        }
        cout << total << "\n";
    }

    return 0;
}