// https://codeforces.com/contest/2260/problem/D

#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

#define int long long
#define ld long double
#define pb push_back
#define eb emplace_back
#define is insert
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define unique(x) (x).erase(unique((x).begin(), (x).end()), (x).end())
#define f(i,b,e) for (int i = (b); i < (e); ++i)
#define rf(i,b,e) for (int i = (b); i >= (e); --i)
#define fa(i,a) for (auto& i : (a))
#define sz(x) ((int)(x).size())
#define fi first
#define se second
#define mkp make_pair
#define mark if(info)
#define fit(x) for(auto it=(x); it!=(x).end(); it++)

using namespace std;
using namespace __gnu_pbds;

using par = array<int,2>;
using ii = pair<int,int>;
using iii = array<int,3>;

typedef vector<int> vi;
typedef vector<ii> vii;
typedef vector<vector<int>> vvi;
typedef set<int> si;
typedef map<int,int> mii;

bool info = true;

template<class T> concept It = requires(T t){begin(t);end(t);} && !is_same_v<T,string>;
template<class T> struct is_arr : false_type {};
template<class T, size_t N> struct is_arr<array<T,N>> : true_type {};

template<class T> void pv(const T& v){
    if constexpr (is_arr<T>::value) { cout<<"("; for(size_t i=0;i<v.size();++i){ pv(v[i]); cout<<" )"[i+1==v.size()]; } }
    else if constexpr (requires{v.first; v.second;}) { cout<<"("; pv(v.first); cout<<" "; pv(v.second); cout<<")"; }
    else if constexpr (It<T>) { cout<<"["; bool f=1; for(auto&x:v){ if(!f) cout<<", "; f=0; pv(x); } cout<<"]"; }
    else cout<<v;
}

template<class T, class... A>
void dbo(const char* n, T v, A... a){
    if(!info) return;
    const char* c = strchr(n,',');
    cout.write(n, c ? c-n : strlen(n)) << "=";
    pv(v);
    if constexpr (sizeof...(a)) cout<<" ", dbo(c+1, a...);
    else cout<<"\n";
}

#define dbg(...) dbo(#__VA_ARGS__, __VA_ARGS__)

template <typename T>
using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

bool all_test = 1;

const int MAXN = 2e5 + 1, MOD = 1e9 + 7, MODW = 998244353, oo = 1ll << 60;

const ld pi = acos(-1.0);

const int offset = 4;
const int LIM = 2*offset+3;

vvi dp;
vector<int> opcoes = {-3,-2,-1,1,2,3};
string s;

bool valido(char sinal, int val){
    if(sinal=='0'){
        return val==0;
    }
    if(sinal=='+'){
        return val>0;
    }
    if(sinal=='-'){
        return val<0;
    }
    return false;
}

int rec(int pos, int val, int n){
    if(val+offset<0 || val+offset >= LIM) return oo;
    if(n==0) return -1;

    if(dp[pos][val+offset]==-1){
        int melhor = oo;

        vector<int> prx;
        fa(x,opcoes){
            if(valido(s[pos], val+x)){
                prx.pb(val+x);
                int temp = max(abs(x), rec(pos+1,val+x,n-1));
                melhor = min(melhor, temp);
            }            
        }
        dp[pos][val+offset]=melhor;

        int off = val+offset;
    }
    return dp[pos][val+offset];
}

void solve() {
    int n; cin >> n;
    cin >> s;

    if(s[0]=='0'){
        cout << "-1\n";
        return;
    }
    f(i,1,n){
        if(s[i-1]==s[i] and s[i]=='0'){
            cout << "-1\n";
            return;
        }
    }

    dp.assign(n, vi(LIM, -1));
    dp[0][0] = 0;

    int ans = rec(0,0,n);
    cout << (ans==oo ? -1 : ans) << "\n";
}

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(nullptr);
    int tc = 1;
    if (all_test) cin >> tc;
    while (tc--) solve();
    return 0;
}