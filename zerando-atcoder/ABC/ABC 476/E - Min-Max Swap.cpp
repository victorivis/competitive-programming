// https://atcoder.jp/contests/abc476/tasks/abc476_e

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

const int MAX = 2e5+10;

int ns[MAX];

#define e(u) (u*2)
#define d(u) (e(u)+1)
#define out (l > r || l > b || r < a)
#define in (a <= l && r <= b)

struct Node {
  int mx = 0;
  int pos_mx = -1;
  int mn = oo;
  int pos_mn = -1;

  Node operator+(const Node b) {

    int npos_mx = (mx>b.mx ? pos_mx : b.pos_mx);
    int npos_mn = (mn<b.mn ? pos_mn : b.pos_mn);

    return {
        max(mx,b.mx),
        npos_mx,
        min(mn,b.mn),
        npos_mn
    };
  }
};

struct SEG {
  Node seg[MAX*4];
  int lim;

  void build(int u, int l, int r) {
    if(l == r) {
      seg[u].mx = 0;
      seg[u].pos_mx = -1;
      seg[u].mn = oo;
      seg[u].pos_mn = -1;
    } else {
      const int m = (l+r)/2;
      build(e(u), l, m), build(d(u), m+1, r);
      seg[u] = seg[e(u)] + seg[d(u)];
    }
  }

  void build(int lim_) {
    lim = lim_-1;
    build(1, 0,lim);
  }

  void update(int u, int l, int r, int a, int b) {
    if(l == r) {
      seg[u] = {b, l, b, l};
      return;
    }
    const int m = (l+r)/2;
    if(a <= m) update(e(u), l, m, a, b);
    else update(d(u), m+1, r, a, b);
    seg[u] = seg[e(u)] + seg[d(u)];
  }

  void update(int pos, int newv) {
    update(1, 0,lim, pos, newv);
  }

  Node query(int u, int l, int r, int a, int b) {
    if(out) return Node();
    if(in) return seg[u];
    const int m = (l+r)/2;
    return query(e(u), l, m, a, b) + query(d(u), m+1, r, a, b);
  }

  Node query(int l, int r) {
    return query(1, 0,lim, l, r);
  }
} seg;

void solve() {
    int n, q; cin >> n >> q;
    vector<int> a(n+1);
    vector<ii> b(q);
    
    seg.build(n+2);

    f(i,1,n+1){
        cin >> a[i];
        seg.update(i,a[i]);
    }

    f(i,0,q){
        cin >> b[i].fi >> b[i].se;
    }

    fa(x,b){
        Node y = seg.query(x.fi, x.se);

        int p1 = y.pos_mn;
        int p2 = y.pos_mx;
        if(p1 != p2){
            swap(a[p1], a[p2]);
            seg.update(p1, a[p1]);
            seg.update(p2, a[p2]);
        }
    }
    f(i,1,n+1){
        cout << a[i] << " ";
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