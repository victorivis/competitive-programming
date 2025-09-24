/*
https://judge.beecrowd.com/en/problems/view/1474
*/

#include <bits/stdc++.h>
using namespace std;

#define int long long

const int LIMITE = 1e8;

void limitar(int& num){
    num = num%LIMITE;
}

vector<vector<int>> mulMat(vector<vector<int>>& mat1, vector<vector<int>>& mat2){
    vector<vector<int>> rslt(mat1.size(), vector<int>(mat2[0].size(), 0));
    
    for (int i = 0; i < mat1.size(); i++) {
        for (int j = 0; j < mat2[0].size(); j++) {
            rslt[i][j] = 0;

            for (int k = 0; k < mat2.size(); k++) {
                rslt[i][j] += mat1[i][k] * mat2[k][j];
            }
            limitar(rslt[i][j]);
        }
    }
    return rslt;
}

void exibir(int num, int pulo){
    if(pulo!=0){
        exibir(num/10, pulo-1);
        cout << num%10;
    }
}

vector<vector<int>> binpow(vector<vector<int>> a, long long b) {
    if (b == 0){
        return {{1, 0}, {0, 1}};
    }
    vector<vector<int>> res = binpow(a, b / 2);
    if (b % 2){
        vector<vector<int>> temp = mulMat(res, res);
        return mulMat(temp,  a);
    }
    else{
        return mulMat(res, res);
    }
}

int32_t main(){
    int n, k, l;
    while(cin >> n >> k >> l){
        n/=5;
        limitar(k);
        limitar(l);
        
        vector<vector<int>> matriz = {{0, 1}, {l, k}};
        vector<vector<int>> sequencia = {{1}, {k}};
        
        vector<vector<int>> temp = sequencia;
        limitar(temp[0][0]);
        limitar(temp[1][0]);
        
        vector<vector<int>> pot = binpow(matriz, n);
        vector<vector<int>> resposta = mulMat(pot, sequencia);
        
        exibir(resposta[0][0], 6);
        cout << "\n";
    }

    return 0;
}