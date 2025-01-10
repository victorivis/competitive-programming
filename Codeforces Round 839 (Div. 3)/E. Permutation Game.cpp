/* https://codeforces.com/contest/1772/problem/E */

#include <bits/stdc++.h>
using namespace std;
 
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    int t; cin >> t;
    while(t--){
        int n; cin >> n;
        vector<int> lista(n);
        
        vector<bool> crescente(n);
        vector<bool> decrescente(n);
        
        int falta1=n;
        int falta2=n;
        
        vector<int> exclusive1;
        vector<int> exclusive2;
        vector<int> nor;
        
        for(int i=0; i<n; i++){
            int x; cin >> x;
            
            lista[i] = x;
            crescente[i] = (x==i+1 ? true : false);
            decrescente[i] = (x==n-i ? true : false);
            
            if(crescente[i]==false && decrescente[i]==false){
                nor.push_back(i);
            }
            else if(crescente[i]==true && decrescente[i]==false){
                exclusive1.push_back(i);
                falta1--;
            }
            else if(crescente[i]==false && decrescente[i]==true){
                exclusive2.push_back(i);
                falta2--;
            }
            else{
                falta1--;
                falta2--;
            }
        }
        
        bool empate=false;
        while(empate==false && falta1!=0 && falta2!=0){
            empate=true;
            
            //turno1
            if(exclusive2.size() > 0){
                falta1--;
                exclusive2.pop_back();
                empate=false;
            }
            else if(falta2>1 && nor.size()>0){
                falta1--;
                falta2--;
                nor.pop_back();
                empate=false;
            }
            if(falta1<=0) break;
            
            //turno2
            if(exclusive1.size() > 0){
                falta2--;
                exclusive1.pop_back();
                empate=false;
            }
            else if(falta1>1 && nor.size()>0){
                falta1--;
                falta2--;
                nor.pop_back();
                empate=false;
            }
        }
        
        if(falta1<=0){
            cout << "First\n";
        }
        else if(falta2<=0){
            cout << "Second\n";
        }
        else{
            cout << "Tie\n";
        }
    }
 
    return 0;
}