// https://atcoder.jp/contests/abc476/tasks/abc476_d

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

using namespace std;
using namespace __gnu_pbds;

using par = array<int,2>;
using ii = pair<int,int>;
using iii = array<int,3>;

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

bool all_test = 0;

const int MAXN = 2e5 + 1, MOD = 1e9 + 7, MODW = 998244353, oo = 1ll << 60;

const ld pi = acos(-1.0);

void solve() {
    int n, m, k; cin >> n >> m >> k;
    int X, Y; cin >> X >> Y;
    vector<int> a(n);
    vector<int> b(m);
    
    f(i,0,n) cin >> a[i];
    f(i,0,m) cin >> b[i];

    sort(all(a));
    sort(all(b));

    vector<int> prefA(n+1,0);
    vector<int> prefB_real(m+1,0);
    vector<int> prefB_k(m+1,0);
    
    f(i,1,n+1){
        prefA[i] = prefA[i-1]+a[i-1];
    }
    
    f(i,1,m+1){
        prefB_real[i] = prefB_real[i-1]+b[i-1];
        prefB_k[i] = prefB_k[i-1] + (b[i-1]+k-1)/k*k;
    }
    
    auto query = [&](int val) -> int {
        int pos = prev(upper_bound(all(prefA), val)) - prefA.begin();
        return pos;
    };

    int ans = query(X+k*Y);
    f(i,0,m+1){
        int have = Y*k;
        int cur = 0;
        bool entrou=false;
        if(prefB_k[i] <= have){
            entrou = true;
            cur=i;
            int extras = have-prefB_real[i];
            int sec = query(X+extras);
            cur += sec;
        }
        ans = max(cur, ans);
    }
    cout << ans << "\n";
}

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(nullptr);
    int tc = 1;
    if (all_test) cin >> tc;
    while (tc--) solve();
    return 0;
}