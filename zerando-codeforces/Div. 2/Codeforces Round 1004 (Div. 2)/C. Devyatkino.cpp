/*
https://codeforces.com/contest/2067/problem/C
*/

#include <bits/stdc++.h>
using namespace std;

vector<int> subtrair =  {3, 4, 5, 6, 7, 8, 9, 0, 1, 2};
vector<int> adicionar = {7, 6, 5, 4, 3, 2, 1, 0, 9, 8};

int main() {
    int t; cin >> t;
    while(t--){
        int n; cin >> n;
        int tempN = n;
        
        vector<int> digitos;
        while(tempN>0){
            digitos.push_back(tempN%10);
            tempN/=10;
        }

        int total=digitos[0];

        int menor=7;
        bool isZero=(digitos[0]==0);
        menor = min(menor, subtrair[digitos[0]]);

        for(int i=1; i<digitos.size(); i++){
            int num = digitos[i];
            int atual = adicionar[num];

            if(total<adicionar[num] && num!=7){
                atual++;
            }
            
            if(num==8){
               atual = min(atual, total+1);
            }
            
            menor = min(menor, atual);
            
            total+=pow(10, i)*digitos[i];
            if(num!=0) isZero=false;
        }

        cout << menor << "\n";
    }
    
    return 0;
}