/*
https://judge.beecrowd.com/en/problems/view/1602
*/

#include <bits/stdc++.h>
using namespace std;

#define ll long long

const int LIM = 2e6+5;
bool vis[LIM]={0};
int spf[LIM];

constexpr void sieve(){
    for(int i=2; i<LIM; i++){
        if(!vis[i]){
            vis[i] = true;
            spf[i] = i;
            
            if((long long)i*i < LIM){
                for(int j=i*i; j<LIM; j+=i){
                    if(!vis[j]){
                        vis[j] = true;
                        spf[j] = i;
                    }
                }
            }
        }
    }
}

int divisores(int num){
    int last=1;
    int cont=0;
    int total=1;
    while(num > 1){
        if(spf[num]!=last){
            total*=cont+1;
            last=spf[num];
            cont=1;
        }
        else{
            cont++;
        }
        num/=spf[num];
    }
    total *= cont+1;
    return total;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    
    sieve();
    int pref[LIM] = {0};
    
    for(int i=2; i<LIM; i++){
        int divi = divisores(i);
        if(spf[divi] == divi) pref[i]++;
        pref[i] += pref[i-1];
    }
    
    int x;
    while(cin >> x){
        cout << pref[x] << "\n";
    }

    return 0;
}