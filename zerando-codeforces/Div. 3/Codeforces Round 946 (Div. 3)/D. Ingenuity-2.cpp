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
bool info = true;

using namespace std;
using namespace __gnu_pbds;

using par = array<int,2>;
using ii = pair<int,int>;
using iii = array<int,3>;

void print_value(const par& v) {cout << "(" << v[0] << " " << v[1] << ")"; }
 
template<typename T>
void print_value(const T& v) { cout << v; }
 
template<typename A, typename B>
void print_value(const pair<A,B>& p) {
    cout << "(";
    print_value(p.first);
    cout << " ";
    print_value(p.second);
    cout << ")";
}
 
template<typename T>
void print_value(const vector<T>& v) {
    cout << "[";
    for (size_t i = 0; i < v.size(); ++i) {
        if (i) cout << ", ";
        print_value(v[i]);
    }
    cout << "]";
}
 
template<typename T>
concept Iterable = requires(T t) {
    begin(t);
    end(t);
};
 
template<Iterable T>
requires (!is_same_v<T, string>)
void print_value(const T& v) {
    cout << "[";
    bool first = true;
    for (const auto& x : v) {
        if (!first) cout << ", ";
        first = false;
        print_value(x);
    }
    cout << "]";
}
 
template<typename T, typename... Args>
void debug_out(const char* names, T value, Args... args) {
    if (!info) return;
    const char* comma = strchr(names, ',');
    if (comma) {
        cout.write(names, comma - names) << "=";
        print_value(value);
        cout << " ";
        if constexpr (sizeof...(args) > 0)
            debug_out(comma + 1, args...);
        else
            cout << '\n';
    } else {
        cout << names << "=";
        print_value(value);
        cout << '\n';
    }
}
 
#define dbg(...) debug_out(#__VA_ARGS__, __VA_ARGS__)

template <typename T>
using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

bool all_test = 1;

const int MAXN = 2e5 + 1, MOD = 1e9 + 7, MODW = 998244353, oo = 1ll << 60;

const ld pi = acos(-1.0);

void solve() {
    int n; cin >> n;
    string s; cin >> s;

    map<char,int> mp;
    f(i,0,n){
        mp[s[i]]++;
    }

    if(mp['N']/2-mp['S']/2 != ((1+mp['N'])/2 - (1+mp['S'])/2)){
        cout << "NO\n";
        return;
    }
    if(mp['E']/2-mp['W']/2 != ((1+mp['E'])/2 - (1+mp['W'])/2)){
        cout << "NO\n";
        return;
    }
    bool maior = false;
    bool diferente = mp['E']+mp['W']>0 && mp['N']+mp['S']>0;
    for(auto& [c, v] : mp){
        if(v > 1) maior = true;
    }

    if(maior==false && diferente==false){
        cout << "NO\n";
        return;
    }
    
    string dir = "NSWE";
    int val[4] = {0};
    fa(c, s){
        int pos = find(all(dir),c) - dir.begin();

        bool condicao = val[pos] < mp[c]/2;
        if(c=='E' || c=='W') condicao = !condicao;

        if(condicao) cout << "R";
        else cout << "H";
        val[pos]++;
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