// https://codeforces.com/contest/2121/problem/C

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

void solve() {
    int n, m; cin >> n >> m;
    vector<vector<int>> mat(n, vector<int>(m));
    
    int maior = 0;
    f(i,0,n){
        f(j,0,m){
            cin >> mat[i][j];
            maior = max(maior, mat[i][j]);
        }
    }

    vector<ii> need;
    f(i,0,n){
        f(j,0,m){
            if(mat[i][j] == maior){
                need.pb({i,j});
            }
        }
    }

    auto func = [&]() -> bool {
        if(need.size()<=2) return true;

        map<int,int> posi;
        map<int,int> posj;

        f(i,0,3){
            posi[need[i].fi]++;
            posj[need[i].se]++;
        }

        int fixedi = -1;
        int fixedj = -1;

        if(posi.size()==3 and posj.size()==3){
            return false;
        }

        fa(x,posi){
            if(x.second>1){
                fixedi = x.fi;
            }
        }
        fa(x,posj){
            if(x.second>1){
                fixedj = x.fi;
            }
        }

        assert(fixedi!=-1 or fixedj!=-1);

        f(i,0,need.size()){
            if(need[i].fi==fixedi or need[i].se==fixedj) continue;
            else if(fixedi==-1){
                fixedi = need[i].fi;
            }
            else if(fixedj==-1){
                fixedj = need[i].se;
            }
            else{
                return false;
            }
        }
        return true;
    };

    cout << maior - func() << "\n";
}

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(nullptr);
    int tc = 1;
    if (all_test) cin >> tc;
    while (tc--) solve();
    return 0;
}