// https://codeforces.com/contest/2259/problem/F

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

using T = long long;
struct Fenwick {
    int n;
    vector<T> bit;

    Fenwick(int n) : n(n), bit(n + 1, 0) {}

    Fenwick(vector<T>& li) : n(li.size()){
        bit.push_back(0);
        bit.insert(bit.end(), li.begin(), li.end());
        
        for(int i=1; i<=n; i++){
            int p = i+(i&-i);
            if(p <= n){
                bit[p] += bit[i];
            }
        }
    }

    void update(int i, int val) {
        for (; i <= n; i += i & -i) bit[i] += val;
    }

    T query(int i) {
        if(i==0) return 0;

        T query = 0;
        for (; i > 0; i -= i & -i) query += bit[i];
        return query;
    }
    
    int kth(T k) {
        int cnt = 0, ret = 0;
        for (int i = __lg(n); ~i; --i) {
            ret += 1 << i;
            if (ret >= n || cnt + bit[ret] >= k)
                ret -= 1 << i;
            else
                cnt += bit[ret];
        }
        return ret + 1;
    }
};

void solve() {
    int n; cin >> n;
    vector<int> a(n);
    
    f(i,0,n) cin >> a[i];
    string s; cin >> s;

    vector<int> st;
    int cur=0;
    rf(i,n-1,0){
        if(a[i]==0) cur++;
        else{
            st.pb(cur);
            cur = 0;
        }
    }
    
    int N = st.size();
    Fenwick fw(st);
    
    int tot=0;
    int acc=0;
    f(i,0,N){
        acc+=st[i];
        tot+=acc;
    }

    cout << tot << " ";

    f(i,0,s.size()){
        int pos = fw.kth(1);
        int tam = N-pos+1;
        int tudo = fw.query(N);
        
        if(tudo==0){
            cout << tot << " ";
            continue;
        }

        if(s[i]=='0'){
            tot -= tam;
            fw.update(pos,-1);
        }
        else{
            int pos = N;
            int val = fw.query(pos)-fw.query(pos-1);
            fw.update(pos,-val);
            tot -= tudo;

            N--;
        }

        cout << tot << " ";
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