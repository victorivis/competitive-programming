/*
https://judge.beecrowd.com/en/problems/view/1110
*/

#include <bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    int n; cin >> n;
    while(n!=0){
        deque<int> lista(n);
        
        for(int i=0; i<n; i++){
            lista[i]=i+1;
        }
        
        cout << "Discarded cards: ";
        while(lista.size()>1){
            cout << lista[0];
            
            if(lista.size()>2){
                cout << ", ";
            }
            
            lista.pop_front();
            lista.push_back(lista[0]);
            lista.pop_front();
        }
        cout << "\n";
        
        cout << "Remaining card: " << lista[0] << "\n";
        
        cin >> n;
    }
    
    return 0;
}