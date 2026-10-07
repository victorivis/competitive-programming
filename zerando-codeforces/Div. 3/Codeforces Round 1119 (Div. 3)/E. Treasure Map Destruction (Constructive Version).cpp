// https://codeforces.com/contest/2259/problem/E

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
    int n; cin >> n;
    vector<int> a(n);
    
    f(i,0,n){
        cin >> a[i];
    }

    if(a == vector<int>(n,-1)){
        cout << string(n,'1') << "\n";
        return;
    }
    
    Intervals st;
    set<int> maybe;
    f(i,0,n){
        if(a[i]!=-1){
            int l = i-a[i];
            int r = i+a[i];

            if(a[i]!=0){
                st.insert({l+1,r-1});
            }
            maybe.insert(l);
            maybe.insert(r);
        }
    }

    vector<int> ans(n);

    f(i,0,n){
        if(maybe.count(i) and st.ok(st.find(i))==false){
            ans[i]=1;
        }
        else{
            ans[i]=0;
        }
    }
    
    auto func = [&](vector<int>& val)->bool{
        int cur = 1ll<<30;
        
        vector<int> left(n);
        f(i,0,n){
            if(val[i]){
                cur = 0;
            }
            left[i] = cur;
            cur++;
        }
        vector<int> right(n);

        cur = 1ll<<30;
        rf(i,n-1,0){
            if(val[i]){
                cur = 0;
            }
            right[i] = cur;
            cur++;
        }

        f(i,0,n){
            if(a[i]!=-1 and a[i]!=(min(left[i], right[i]))){
                return false;
            }
        }
        return true;
    };

    if(func(ans)){
        f(i,0,n){
            cout << ans[i];
        }
        cout << "\n";
    }
    else{
        cout << "-1\n";
    }
}

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(nullptr);
    int tc = 1;
    if (all_test) cin >> tc;
    while (tc--) solve();
    return 0;
}