// https://codeforces.com/contest/2150/problem/A

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

struct Intervals {
    using P = array<int,2>;
    using it_t = set<P>::iterator;
    set<P> st;
    
    bool ok(it_t it) const { return it != st.end(); }
    
    it_t find(int x) {
        auto it = st.upper_bound({x, INT_MAX});
        if (it==st.begin()) return st.end();
        --it;
        return ((*it)[0] <= x && x <= (*it)[1]) ? it : st.end();
    }
    
    it_t find(P p) {
        auto [l, r] = p;
        auto it = find(l);
        return (ok(it) && (*it)[1] >= r) ? it : st.end();
    }
    
    void insert(int x) { insert(P{x, x}); }

    void insert(P p) {
        auto [l, r] = p;
        auto it = st.lower_bound({l, INT_MIN});

        if (it != st.begin()) {
            auto pv = prev(it);
            if ((*pv)[1] + 1 >= l) {
                l = min(l, (*pv)[0]);
                r = max(r, (*pv)[1]);
                it = st.erase(pv);
            }
        }

        while (it != st.end() && (*it)[0] <= r + 1) {
            r = max(r, (*it)[1]);
            it = st.erase(it);
        }

        st.insert({l, r});
    }
};

void solve() {
    int n, m; cin >> n >> m;
    string s; cin >> s;
    vi poses(m);
    
    Intervals st;
    f(i,0,m){
        cin >> poses[i];
        st.insert(poses[i]);
    }

    deque<char> a(all(s));
    int r=1;
    int pos=1;
    auto apply = [&](char c, int cur) -> int {
        if(c=='A') return cur+1;
        assert(c=='B');
        
        auto it = st.find(cur+1);
        if(st.ok(it)){
            return (*it)[1]+1;
        }
        return cur+1;
    };

    f(i,0,n){
        if(i!=0){
            pos = apply(a[0], pos);
            a.pop_front();
        }

        assert(a.size());

        int cur = pos;
        cur = apply(a[0], cur);
        
        if(st.ok(st.find(cur))==false){
            st.insert(cur);
        }
    }


    vi ans;
    fa(x,st.st){
        f(i,x[0],x[1]+1){
            ans.pb(i);
        }
    }

    cout << ans.size() << "\n";
    fa(x,ans){
        cout << x << " ";
    }
    cout << "\n";
}

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(nullptr);
    int tc = 1;
    if (all_test) cin >> tc;
    while (tc--) solve();
    return 0;
}