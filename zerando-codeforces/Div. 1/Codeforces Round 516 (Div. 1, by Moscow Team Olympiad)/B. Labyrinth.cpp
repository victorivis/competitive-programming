// https://codeforces.com/contest/1063/problem/B

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

bool all_test = 0;

const int MAXN = 2e5 + 1, MOD = 1e9 + 7, MODW = 998244353, oo = 1ll << 60;

const ld pi = acos(-1.0);

vi di = {-1,1,0,0};
vi dj = {0,0,1,-1};

void solve() {
    int n, m; cin >> n >> m;
    int x, y; cin >> x >> y;
    int left, right; cin >> left >> right;

    x--, y--;
    
    vector<string> mat(n);
    f(i,0,n){
        cin >> mat[i];
    }

    auto conv = [&](int a, int b) -> int {
        return a*m+b;
    };

    auto rev = [&](int val) -> ii{
        return {val/m, val%m};
    };

    auto valido = [&](ii pos) -> bool {
        return (0<=pos.fi and pos.fi<n and 0<=pos.se and pos.se<m);
    };

    vi vis(n*m);

    deque<iii> ordem;    
    ordem.pb({0,0,conv(x,y)});

    while(ordem.size()){
        auto [l,r,pos] = ordem[0];
        ordem.pop_front();

        assert(l<=left and r<=right);

        if(vis[pos]) continue;
        vis[pos] = 1;
        
        ii cur = rev(pos);
        f(i,0,4){
            ii nxt = cur;
            nxt.fi += di[i];
            nxt.se += dj[i];
            int val_nxt = conv(nxt.fi, nxt.se);

            int nxt_l = l+(dj[i]==-1);
            int nxt_r = r+(dj[i]==1);

            if(nxt_l>left or nxt_r>right) continue;

            if(valido(nxt) and mat[nxt.fi][nxt.se] != '*' and vis[val_nxt]==0){
                if(dj[i]) ordem.push_back({nxt_l, nxt_r, val_nxt});
                else ordem.push_front({nxt_l, nxt_r, val_nxt});
            }
        }
    }

    int ans=0;
    fa(x,vis) ans+=x;

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