// https://codeforces.com/contest/2219/problem/A

// https://codeforces.com/problemset/problem/2219/A

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

vector<int> divisores(int n){
    vector<int> a;
    f(i,1,(int)sqrt(n)+1){
        if(n%i==0){
            a.pb(i);
            a.pb(n/i);
        }
    }
    return a;
}

int tri(int num){
    return num*(num+1)/2;
}

void solve() {
    int a, b; cin >> a >> b;
    int um = a;
    int dois = b;

    int tot = a + b*2;
    int N = 2*tot+1;
    
    vector<int> div = divisores(N);
    
    f(i,0,div.size()){
        int div1 = div[i];
        int div2 = div[++i];

        if( (div1&1) and (div2&1) ){
            bool cond1 = (div1-1)%2==0;
            bool cond2 = (div1-1)%2==0;

            if(cond1 and cond2){
                int x = (div1-1)/2;
                int y = (div2-1)/2;

                if(!x or !y) continue;

                int quad = min(x,y);
                int ext = max(x,y)-quad;
                
                int min_dois = 0;
                int max_dois = ext*quad + tri(quad)*2;
                
                int min_um = tot - max_dois*2;
                int max_um = tot;
                
                if(min_dois<=dois and dois<=max_dois and min_um<=um and um<=max_um){
                    cout << x << " " << y << "\n";
                    return;
                }
            }
        }
    }

    cout << "-1\n";
}

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(nullptr);
    int tc = 1;
    if (all_test) cin >> tc;
    while (tc--) solve();
    return 0;
}