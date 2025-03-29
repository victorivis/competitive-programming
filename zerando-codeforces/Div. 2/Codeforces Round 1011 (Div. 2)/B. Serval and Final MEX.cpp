/*
https://codeforces.com/contest/2085/problem/B
*/

#include <bits/stdc++.h>
using namespace std;

vector<int> l;

bool hasZero(int i, int j){
    while(i<=j){
        if(l[i]==0) return true;
        i++;
    }
    
    return false;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    int t; cin >> t;
    while(t--){
        int n; cin >> n;
        
        l.assign(n, 0);
        
        for(int i=0; i<n; i++){
            cin >> l[i];
        }
        
        int half=n/2;
        
        bool n1 = hasZero(0, half-1);
        bool n2 = hasZero(half, n-1);
        
        int novoTam = n-(half-1);
        
        if(n1==false && n2==false){
            cout << "1\n";
            cout << "1 " << n << "\n";
        }
        else if(n1==false && n2==true){
            cout << "2\n";
            
            cout << half+1 <<  " " << n << "\n";
            cout << "1 " << half+1 << "\n";
        }
        else if(n1==true && n2==false){
            cout << "2\n";
            
            cout << "1 " << half << "\n";
            cout << "1 " << novoTam << "\n";
        }
        else if(n1==true && n2==true){
            cout << "3\n";
            
            cout << half+1 << " " << n << "\n";
            cout << "1 " << half << "\n";
            cout << "1 2\n";
        }
    }
    
    return 0;
}