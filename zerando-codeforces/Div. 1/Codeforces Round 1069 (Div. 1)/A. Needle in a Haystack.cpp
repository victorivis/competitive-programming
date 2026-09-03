// https://codeforces.com/contest/2174/problem/A

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

void no(){
    cout << "Impossible\n";
}

void solve() {
    string s1, s2; cin >> s1 >> s2;

    map<char,int> d;
    fa(c,s2){
        d[c]++;
    }
    fa(c,s1){
        d[c]--;
    }

    int n = s2.size();
    s2 = "";

    fa(x,d){
        if(x.second < 0) return (void) no();
        if(x.second == 0) continue;
        
        s2 += string(x.second, x.first);
    }

    sort(all(s2));

    s1 += 'z'+1;
    s2 += 'z'+1;
    int p1=0, p2=0;

    string ans = "";
    
    while(ans.size()<n){
        if(s1[p1]==s2[p2]){
            int cont=0;
            string extras;

            int p11 = p1;
            int p22 = p2;

            while(s1[p11] == s2[p22]){
                if(extras.size() and extras.back() < s1[p11]){
                    ans += extras;
                    ans += extras;
                    p1 = p11;
                    p2 = p22;
                    break;
                }

                extras += s1[p11];
                cont++;                
                p11++;
                p22++;
            }

            if(p1 == p11) continue;         
            
            if(s1[p11] < s2[p22]){
                p1 = p11;
                ans += extras;
            }
            else{
                p2 = p22;
                ans += extras;
            }
            continue;
        }
        
        if(s1[p1] < s2[p2]){
            ans += s1[p1];
            p1++;
        }
        else{
            ans += s2[p2];
            p2++;
        }
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