/*
https://www.spoj.com/problems/FACT0/
*/

#include <bits/stdc++.h>
using namespace std;
 
using u64 = uint64_t;
using u128 = __uint128_t;
 
u64 binpower(u64 base, u64 e, u64 mod) {
    u64 result = 1;
    base %= mod;
    while (e) {
        if (e & 1)
            result = (u128)result * base % mod;
        base = (u128)base * base % mod;
        e >>= 1;
    }
    return result;
}
 
bool check_composite(u64 n, u64 a, u64 d, int s) {
    u64 x = binpower(a, d, n);
    if (x == 1 || x == n - 1)
        return false;
    for (int r = 1; r < s; r++) {
        x = (u128)x * x % n;
        if (x == n - 1)
            return false;
    }
    return true;
};
 
bool MillerRabin(u64 n) {
    if (n < 2)
        return false;
 
    int r = 0;
    u64 d = n - 1;
    while ((d & 1) == 0) {
        d >>= 1;
        r++;
    }
 
    for (int a : {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37}) {
        if (n == a)
            return true;
        if (check_composite(n, a, d, r))
            return false;
    }
    return true;
}
 
long long mult(long long a, long long b, long long mod) {
    return (__int128)a * b % mod;
}
 
long long f(long long x, long long c, long long mod) {
    return (mult(x, x, mod) + c) % mod;
}
 
long long gcd(long long a, long long b){
    if(b==0) return a;
    if(a==0) return b;
    return gcd(b%a, a);
}

//Implementacao do Pollard Rho pelo metodo de Brent-Dekker
long long brent(long long n, long long x0=2, long long c=1) {
    long long x = x0;
    long long g = 1;
    long long q = 1;
    long long xs, y;
 
    int m = 128;
    int l = 1;
    while (g == 1) {
        y = x;
        for (int i = 1; i < l; i++)
            x = f(x, c, n);
        int k = 0;
        while (k < l && g == 1) {
            xs = x;
            for (int i = 0; i < m && i < l - k; i++) {
                x = f(x, c, n);
                q = mult(q, abs(y - x), n);
            }
            g = gcd(q, n);
            k += m;
        }
        l *= 2;
    }
    if (g == n) {
        do {
            xs = f(xs, c, n);
            g = gcd(abs(xs - y), n);
        } while (g == 1);
    }
    return g;
}
 
unordered_map<long long, long long> fatores;
 
long long divisor(long long n){
    if(fatores.count(n)==0){
        if(n%2==0){
            fatores[n]=2;
        }
        else if(MillerRabin(n)){
            fatores[n]=n;
        }
        else{
            int resultado;
            for (int a : {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37}) {
                resultado = brent(n, a, 1);
                
                if(resultado!=n && resultado!=1){
                    break;
                }
            }
            
            fatores[n]=resultado;
        }
    }
    return fatores[n];
}
 
void fatorar(long long n, map<long long, int>& fatores){
    long long resultado = divisor(n);
    
    if(n==resultado){
        fatores[n]++;
        return;
    }
    fatorar(resultado, fatores);
    fatorar(n/resultado, fatores);
}
 
int main(){
    fatores[1]=1;
    long long n; cin>>n;
    while(n){
        map<long long, int> resposta;
        fatorar(n, resposta);
        
        bool primeiro=true;
        for(auto& p: resposta){            
            cout << p.first << "^" << p.second << " "; 
        }
        cout << "\n";
        
        cin >> n;
    }
 
    return 0;
}