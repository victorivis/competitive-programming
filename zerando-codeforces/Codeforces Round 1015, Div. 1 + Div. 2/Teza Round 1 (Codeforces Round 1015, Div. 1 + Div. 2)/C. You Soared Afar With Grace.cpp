// https://codeforces.com/contest/2084/problem/C

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
    vii a(n);
    f(i,0,n) cin >> a[i].fi;
    f(i,0,n) cin >> a[i].se;

    map<ii,si> d;
    set<int> st;

    f(i,0,n){
        d[a[i]].is(i);
    }

    auto comp = [&](ii x) -> ii {
        return {x.se, x.fi};
    };

    auto troca = [&](int i, int j) -> void {
        assert(d[a[i]].erase(i));
        assert(d[a[j]].erase(j));
        swap(a[i],a[j]);
        assert(d[a[i]].is(i).se);
        assert(d[a[j]].is(j).se);
    };

    auto del = [&](int i, int j) -> void {
        assert(d[a[i]].erase(i));
        assert(d[a[j]].erase(j));
    };

    int extras = n&1;

    vii ans;

    fa(x,d){
        ii c = comp(x.fi);
        assert(x.se.size()==1);

        if(c!=x.fi){
            if(x.se.size() != d[c].size()){
                cout << "-1\n";
                return;
            }
        }
        else{
            if(x.se.size()&1){
                extras--;
                if(extras<0){
                    cout << "-1\n";
                    return;
                }

                int m = n/2;
                if(x.se.count(m)==0){
                    int pos = *x.se.begin();
                    troca(m, pos);

                    assert(x.se.erase(m));
                    ans.pb({pos+1,m+1});
                }
            }
        }
    }

    
    if(extras){
        cout << "-1\n";
        return;
    }

    f(i,0,n/2){
        int j = n-i-1;

        ii c = comp(a[i]);
        if(a[j]!=c){
            int pos = *d[c].rbegin();
            troca(pos,j);
            ans.pb({pos+1,j+1});
        }

        assert(comp(a[j])==a[i]);
        del(i,j);
    }

    cout << ans.size() << "\n";
    fa(x,ans){
        cout << x.fi << " " << x.se << "\n";
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