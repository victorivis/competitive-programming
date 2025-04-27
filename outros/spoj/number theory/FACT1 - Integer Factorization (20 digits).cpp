#include <bits/stdc++.h>
using namespace std;
 
using u64 = uint64_t;
using u128 = __uint128_t;
 
__int128_t abs128(__int128_t x) {
    return x < 0 ? -x : x;
}
 
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
 
__uint128_t mult(__uint128_t a, __uint128_t b, __uint128_t mod) {
    return (__int128)a * b % mod;
}
 
__uint128_t f(__uint128_t x, __uint128_t c, __uint128_t mod) {
    return (mult(x, x, mod) + c) % mod;
}
 
__uint128_t gcd(__uint128_t a, __uint128_t b){
    if(b==0) return a;
    if(a==0) return b;
    return gcd(b%a, a);
}

//Implementacao do Pollard Rho pelo metodo de Brent-Dekker
__uint128_t brent(__uint128_t n, __uint128_t x0=2, __uint128_t c=1) {
    __int128_t x = x0;
    __int128_t g = 1;
    __int128_t q = 1;
    __int128_t xs, y;
 
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
                q = mult(q, abs128(y - x), n);
            }
            g = gcd(q, n);
            k += m;
        }
        l *= 2;
    }
    if (g == n) {
        do {
            xs = f(xs, c, n);
            g = gcd(abs128(xs - y), n);
        } while (g == 1);
    }
    return g;
}
 
unordered_map<__uint128_t, __uint128_t> fatores;
 
__uint128_t divisor(__uint128_t n){
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
 
void fatorar(__uint128_t n, map<__uint128_t, __uint128_t>& fatores){
    long long resultado = divisor(n);
    
    if(n==resultado){
        fatores[n]++;
        return;
    }
    fatorar(resultado, fatores);
    fatorar(n/resultado, fatores);
}
 
__uint128_t string_to_uint128(const std::string& s) {
    __uint128_t result = 0;
    for (char c : s) {
        result = result * 10 + (c - '0');
    }
    return result;
}
 
void print_uint128(__uint128_t n) {
    if (n == 0) {
        printf("0");
        return;
    }
 
    std::string result;
    while (n > 0) {
        result += '0' + (n % 10);
        n /= 10;
    }
 
    std::reverse(result.begin(), result.end());
    printf("%s", result.c_str());
}
 
int32_t main(){
    fatores[1]=1;
    
    string input;
    cin >> input;
 
    __uint128_t n = string_to_uint128(input);
    while(n){
        map<__uint128_t, __uint128_t> resposta;
        fatorar(n, resposta);
        
        bool primeiro=true;
        for(auto& p: resposta){
            print_uint128(p.first);
            printf("^");
            print_uint128(p.second);
            printf(" ");
        }
        printf("\n");
        
        cin >> input;
        n = string_to_uint128(input);
    }
 
    return 0;
}