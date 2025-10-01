/* https://codeforces.com/gym/348180/problem/I */

#include <bits/stdc++.h>
using namespace std;

const int LIM = 1e6+10;
int crivo[LIM] = {0};

void sieve(){
    crivo[1]=1;
    for(int i=2; i<LIM; i++){
        if(crivo[i]==0){
            crivo[i]=i;
            for(long long j = (long long) i*i; j<LIM; j+=i){
                crivo[j]=i;
            }
        }
    }
}

int soma[LIM] = {0};

bool fatora(int num){
    bool mudou=false;
    while(num!=1){
        int total=0;
        int divisor = crivo[num];
        while(num % divisor == 0){
            total++;
            num/=divisor;
        }
        
        if(total > soma[divisor]){
            soma[divisor] = total;
            mudou = true;
        }
    }
    
    return mudou;
}

int main(){
    sieve();
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    int n, k; cin >> n >> k;
    
    int temp = 1;
    for(int i=0; i<n; i++){
        int x; cin >> x;
        fatora(x);
    }
    
    if(!fatora(k)){
        cout << "Yes\n";
    }
    else{
        cout << "No\n";
    }

    return 0;
}