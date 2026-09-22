// https://codeforces.com/contest/2055/problem/C

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

bool info = false;

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
    int n, m; cin >> n >> m;
    string s; cin >> s;
    vector<vector<int>> mat(n, vector<int>(m));
    vi depL(n);
    vi depC(m);

    ii pos = {0,0};

    f(i,0,n){
        f(j,0,m){
            cin >> mat[i][j];
        }
    }

    vector<int> pref_linha(n);
    vector<int> pref_coluna(m);

    f(i,0,n){
        int acc = 0;
        f(j,0,m){
            acc += mat[i][j];
        }
        pref_linha[i] = acc;
    }

    f(j,0,m){
        int acc = 0;
        f(i,0,n){
            acc += mat[i][j];
        }
        pref_coluna[j] = acc;
    }

    map<int,set<int>> dL;
    map<int,set<int>> dC;
    dL[pos.fi].insert(pos.se);
    dC[pos.se].insert(pos.fi);

    vector<ii> bad = {pos};
    fa(c,s){
        if(c=='D') pos.fi++;
        else pos.se++;

        dL[pos.fi].insert(pos.se);
        dC[pos.se].insert(pos.fi);
        bad.pb(pos);
    }

    queue<ii> pq;    
    fa(x,bad){
        int val = min(dL[x.fi].size(), dC[x.se].size());
        if(val==1){
            pq.push(x);
        }
    }

    while(!pq.empty()){
        ii pos = pq.front();
        pq.pop();
        
        bool cond1 = dL[pos.fi].size()==1;
        bool cond2 = dC[pos.se].size()==1;
        
        int novo;
        if(cond1){
            novo = -pref_linha[pos.fi];
        }
        else if(cond2){
            novo = -pref_coluna[pos.se];
        }

        if(cond1 or cond2){            
            assert(dL[pos.fi].erase(pos.se));
            assert(dC[pos.se].erase(pos.fi));
            
            pref_linha[pos.fi] += novo;
            pref_coluna[pos.se] += novo;
            mat[pos.fi][pos.se] = novo;
            
            if(dL[pos.fi].size()==1){
                ii prx = {pos.fi, *dL[pos.fi].begin()};
                pq.push(prx);
            }
            if(dC[pos.se].size()==1){
                ii prx = {*dC[pos.se].begin(), pos.se};
                pq.push(prx);
            }
        }
    }

    f(i,0,n){
        f(j,0,m){
            cout << mat[i][j] << " ";
        }
        cout << "\n";
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