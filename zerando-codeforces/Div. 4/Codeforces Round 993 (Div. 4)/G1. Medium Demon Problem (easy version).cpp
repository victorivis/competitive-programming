// https://codeforces.com/contest/2044/problem/G1

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
#define fit(x) for(auto it=(x).begin(); it!=(x).end(); it++)
#define show(x) (x==oo ? -1 : x)

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

void solve() {
    int n; cin >> n;

    vi b(n,1);
    vi filhos(n);
    vvi rev(n);
    
    f(i,0,n){
        int x; cin >> x;
        x--;
        filhos[i] = x;
        rev[x].pb(i);
    }
    
    vi vis(n,0);
    vi ciclo(n, 0);

    int pivot=-1;
    auto dfs = [&](auto& dfs, int v, int p) -> int {
        if(vis[v]==2) return 0;
        
        vis[v] = 1;

        if(vis[filhos[v]]==1) pivot = filhos[v];
        
        int val = (vis[filhos[v]]==1) || dfs(dfs,filhos[v],v);
        ciclo[v] = val;

        vis[v] = 2;
        if(v == pivot) return 0;
        return val;
    };

    auto dp = [&](auto& dp, int v) -> int {
        int soma = b[v];
        fa(u, rev[v]){
            if(ciclo[u]) continue;
            soma = max(soma, 1+dp(dp,u));
        }
        return soma;
    };

    f(i,0,n){
        if(vis[i]==false){
            dfs(dfs,i,-1);
        }
    }

    int mx = -1;
    f(i,0,n){
        if(ciclo[i]){
            int sm = dp(dp,i) - b[i];
            mx = max(sm, mx);
        }
    }
    cout << mx+2 << "\n";
}

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(nullptr);
    int tc = 1;
    if (all_test) cin >> tc;
    while (tc--) solve();
    return 0;
}