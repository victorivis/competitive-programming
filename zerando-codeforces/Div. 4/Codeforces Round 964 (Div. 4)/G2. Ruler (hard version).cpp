// https://codeforces.com/problemset/problem/1999/G2

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

int query(int l, int r){
    cout << "? " << l << " " << r << endl;
    int x; cin >> x;

    if(x==l*(r+1)) return 0;
    if(x==l*r) return -1;
    if(x==(l+1)*(r+1)) return 1;

    assert(false);
};

void solve() {
    int l=1;
    int r=1000;
    while(r-l>2){
        int m1 = (2*l+r)/3;
        int m2 = (l+2*r+2)/3;
        int dir = query(m1, m2);

        if(dir == 0){
            l = m1;
            r = m2;
        }
        else if(dir == -1){
            l = m2;
        }
        else{
            r = m1;
        }
    };

    if(r-l<2){
        cout << "! " << l+1 << endl;
    }
    else{
        int x = query(l,r-1);
        if(x==0){
            cout << "! " << l+1 << endl;
        }
        else if(x==-1){
            cout << "! " << l+2 << endl;
        }
        else assert(false);
    }
}

signed main() {
    int tc = 1;
    if (all_test) cin >> tc;
    while (tc--) solve();
    return 0;
}