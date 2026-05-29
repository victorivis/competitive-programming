/*
https://codeforces.com/contest/1923/problem/C
*/

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
bool info = false;

using namespace std;
using namespace __gnu_pbds;

template<typename T, typename... Args>
void debug_out(const char* names, T value, Args... args) {
    if(info == false) return;
    const char* comma = strchr(names, ',');

    if (comma) {
        cout.write(names, comma - names) << "=" << value << " ";

        if constexpr (sizeof...(args) > 0)
            debug_out(comma + 1, args...);
        else
            cout << '\n';
    } else {
        cout << names << "=" << value << '\n';
    }
}

#define dbg(...) debug_out(#__VA_ARGS__, __VA_ARGS__)

template <typename T>
using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

bool all_test = 1;

using par = array<int,2>;
using ii = pair<int,int>;
using iii = array<int,3>;

const int MAXN = 2e5 + 1, MOD = 1e9 + 7, MODW = 998244353, oo = 1ll << 60;

const ld pi = acos(-1.0);

void solve() {
    int n, q; cin >> n >> q;
    vector<int> arr(n);
    
    vector<int> pref(n+1,0);
    vector<int> uns(n+1,0);
    f(i,0,n){
        cin >> arr[i];
        pref[i+1] = pref[i]+arr[i]; 
        uns[i+1] = uns[i] + (arr[i]==1);
    }
    
    f(i,0,q){
        int l, r; cin >> l >> r;
        int val1 =  uns[r]-uns[l-1];
        int soma = pref[r]-pref[l-1];
        int dist = r-l+1;
        int naoUm = dist - val1;
        
        if(dist!=1 and 2*val1+(dist-val1)<=soma){
            cout << "YES\n";
        }
        else{
            cout << "NO\n";
        }
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