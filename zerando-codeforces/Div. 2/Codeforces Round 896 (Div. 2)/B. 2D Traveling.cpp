// https://codeforces.com/contest/1869/problem/B

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

using vi = vector<int>;
using vii = vector<ii>;
using vvi = vector<vector<int>>;
using si = set<int>;
using mii = map<int,int>;

bool info = true;

template<class T1,class T2>ostream& operator<<(ostream& out,const pair<T1,T2>& v){
    return out<<'('<<v.fi<<","<<v.se<<')';
}
template<class C>auto operator<<(ostream& out,const C& v)->decltype(
    v.begin(),v.end(),
    typename enable_if<!is_convertible<C,string>::value>::type(),out){

    out<<"[ ";
    for(const auto& y:v)
        out<<y<<" ";
    return out<<"]";
}
template<class T,class... A>void _dbg(const char* s,const T& x,const A&... r){
    int b=0;
    while(*s&&(*s!=','||b)){
        b+=(*s=='('||*s=='['||*s=='{')-(*s==')'||*s==']'||*s=='}');
        cerr<<*s++;
    }
    cerr<<"="<<x;
    if constexpr(sizeof...(r)){
        cerr<<" ";_dbg(s+1+(s[1]==' '),r...);
    }else cerr<<"\n";
}
#define dbg(...) {_dbg(#__VA_ARGS__,__VA_ARGS__);}

template <typename T>
using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

bool all_test = 1;

const int MAXN = 2e5 + 1, MOD = 1e9 + 7, MODW = 998244353, oo = 1ll << 60;

const ld pi = acos(-1.0);

int func(ii& x, ii& y){
    return abs(x.fi - y.fi) + abs(x.se - y.se);
}

void solve() {
    int n, k, st, ed; cin >> n >> k >> st >> ed;
    st--; ed--;

    vii major, minor, a;
    f(i,0,k){
        int x, y; cin >> x >> y;
        a.pb({x,y});
        major.pb(a.back());
    }

    f(i,0,n-k){
        int x, y; cin >> x >> y;
        a.pb({x,y});
        minor.pb(a.back());
    }

    int ans = func(a[st], a[ed]);

    ii vst = a[st];
    ii ved = a[ed];

    int mn1=oo;
    int mn2=oo;
    fa(x, major){
        mn1 = min(mn1, func(vst, x));
        mn2 = min(mn2, func(ved, x));
    }

    cout << min(ans, mn1+mn2) << "\n";
}

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(nullptr);
    int tc = 1;
    if (all_test) cin >> tc;
    while (tc--) solve();
    return 0;
}