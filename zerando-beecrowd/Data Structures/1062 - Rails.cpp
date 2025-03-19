/*
https://judge.beecrowd.com/en/problems/view/1062
*/

#include <bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    int t;
    
    inicio:
    cin >> t;
    while(t!=0){
        stack<int> vet;
        
        int atual=t;
        
        vector<int> lista(t);
        for(int i=0; i<t; i++){
            cin >> lista[i];
            if(lista[i]==0){
                cout << "\n"; 
                goto inicio;
            }
        }
        
        for(int i=t-1; i>=0; i--){
            int x=lista[i];
            
            vet.push(x);
            
            while(vet.empty()==false && vet.top()==atual){
                vet.pop();
                atual--;
            }
        }
        
        if(vet.empty()){
            cout << "Yes\n";
        }
        else{
            cout << "No\n";
        }
    }
    
    return 0;
}