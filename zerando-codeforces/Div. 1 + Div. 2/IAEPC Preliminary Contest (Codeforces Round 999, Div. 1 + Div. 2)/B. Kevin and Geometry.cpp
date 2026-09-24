// https://codeforces.com/contest/2061/problem/B

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
    vector<int> a(n);    
    map<int,int> d;
    f(i,0,n){
        cin >> a[i];
        d[a[i]]++;
    }

    sort(all(a));
    vector<iii> possibilidades;
    f(i,1,n){
        iii temp{a[i]-a[i-1],a[i],a[i-1]};
        possibilidades.pb(temp);
    }
    sort(all(possibilidades));
    fit(d){        
        if(it->se>1){
            it->se -= 2;
            bool encontrou=false;
            iii temp;
            fa(x,possibilidades){
                int v1 = x[2];
                int v2 = x[1];
                
                d[v1]--;
                d[v2]--;
                bool cond = d[v1]>=0 and d[v2]>=0;
                d[v1]++;
                d[v2]++;
                if(cond){
                    temp = x;
                    encontrou = true;
                    break;
                }
            }
            
            if(encontrou && temp[0] < 2*(it->fi)){
                std::cout << temp[1] << " " << temp[2] << " " << (it->fi) << " " << (it->fi) << "\n";
                return;
            }
            if(it!=d.begin() and next(it)!=d.end()){
                int prv = prev(it)->first;
                int nxt = next(it)->first;

                if(nxt-prv < 2*(it->fi)){
                    std::cout << nxt << " " << prv << " " << (it->fi) << " " << (it->fi) << "\n";
                    return;
                }
            }

            it->se += 2;
        }
    }
    std::cout << "-1\n";
}

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(nullptr);
    int tc = 1;
    if (all_test) cin >> tc;
    while (tc--) solve();
    return 0;
}