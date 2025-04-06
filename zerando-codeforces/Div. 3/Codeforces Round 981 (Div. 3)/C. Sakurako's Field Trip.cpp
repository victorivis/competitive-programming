/*
https://codeforces.com/contest/2033/problem/C
*/

#include <bits/stdc++.h>
using namespace std;

int main(){
    int t; cin >> t;
    while(t--){
        int n; cin >> n;
        vector<int> lista(n);
        
        for(int& i: lista){
            cin >> i;
        }
        
        int total=0;
        
        
        int l=1, r=lista.size()-2;
        
        while(l<=r){
            int temp1 = (lista[l-1]==lista[l]) + (lista[r]==lista[r+1]);
            int temp2 = (lista[l-1]==lista[r]) + (lista[l]==lista[r+1]);
            
            if(temp2 < temp1){
                swap(lista[l], lista[r]);
                total+=temp2;
            }
            else{
                total+=temp1;
            }
            
            l++;
            r--;
        }
        
        if(l-r==1 && lista[l]==lista[r]){
            total++;
        }
        
        cout << total << "\n";
    }

    return 0;
}