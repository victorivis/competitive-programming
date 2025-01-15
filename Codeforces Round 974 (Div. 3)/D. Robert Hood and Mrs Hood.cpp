/* https://codeforces.com/contest/2014/problem/D */

#include <bits/stdc++.h>
using namespace std;
 
int main(){
    int t; cin >> t;
    while(t--){
        int n, d, k; cin >> n >> d >> k;
        
        vector<int> menos(n+4, 0);
        vector<int> mais(n+4, 0);
        
        for(int i=0; i<k; i++){
            int l, r; cin >> l >> r;
            menos[r+1]--;
            mais[l]++;
            
            //cout << "(" << l << ", " << r << ") ";
        }
        //cout << "\n";
        
        int pl=1, pr=1;
        int atual=0;
        
        while(pr<=d){
            atual+=mais[pr++];
        }
        int maior=atual, menor=atual;
        int posMenor=1, posMaior=1;
        
        while(pl<=n-d){
            pl++;
            
            atual += menos[pl] + mais[pr];
            
            if(atual < menor){
                menor = atual;
                posMenor=pl;
            }
            if(atual > maior){
                maior = atual;
                posMaior=pl;
            }
            
            pr++;
        }
        
        cout << posMaior << " " << posMenor << "\n";
    }
 
    return 0;
}