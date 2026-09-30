// https://codeforces.com/contest/1411/problem/C

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

void print(priority_queue<ii> pq){
    while(pq.empty()==false){
        auto [x,y] = pq.top();
        cout << "(" << x << "," << y << ") ";
        pq.pop();
    }
    cout << "\n";
}

void solve() {
    int n, m; cin >> n >> m;
    vector<ii> a(m);
    f(i,0,m){
        cin >> a[i].fi >> a[i].se;
        
    }

    vector<int> coluna(n+1,-1);
    vector<int> linha(n+1,-1);
    vector<int> diag(n+1, 0);

    fa(x,a){
        coluna[x.se] = x.fi;
        linha[x.fi] = x.se;

        if(x.se == x.fi){
            diag[x.fi] = true;
        }
    }

    priority_queue<ii> pq;
    f(i,1,n+1){
        int quant = (linha[i]!=-1) + (coluna[i]!=-1);
        if(quant){
            pq.push({-quant, i});
        }
    }

    int ans = 0;
    while(pq.empty()==false){
        auto [val, pos] = pq.top();
        pq.pop();

        if(diag[pos]) continue;
        val = (linha[pos]!=-1) + (coluna[pos]!=-1);

        if(val==1){
            int prx;
            if(linha[pos]!=-1){
                prx = linha[pos];

                linha[pos] = -1;
                coluna[prx] = -1;
            }
            else if(coluna[pos]!=-1){
                prx = coluna[pos];

                coluna[pos] = -1;
                linha[prx] = -1;
            }
            else{
                continue;
            }

            int quant = (linha[prx]!=-1) + (coluna[prx]!=-1);
            
            if(quant){
                pq.push({-quant, prx});
            }
            ans++;
        }
        else if(val==2){
            int prx = linha[pos];
            linha[pos] = -1;
            coluna[prx] = -1;
            ans+=2;

            int quant = (linha[prx]!=-1) + (coluna[prx]!=-1);
            if(quant){
                pq.push({-quant, prx});
            }
        }
        else{
            continue;
        }

        diag[pos] = true;
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