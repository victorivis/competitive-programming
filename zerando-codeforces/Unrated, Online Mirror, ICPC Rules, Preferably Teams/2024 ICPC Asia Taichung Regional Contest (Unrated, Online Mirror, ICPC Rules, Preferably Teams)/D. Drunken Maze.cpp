// https://codeforces.com/problemset/problem/2041/D

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
using iiii = array<int,4>;

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

bool all_test = 0;

const int MAXN = 2e5+10, MOD = 1e9 + 7, MODW = 998244353, oo = 1ll << 60;

const ld pi = acos(-1.0);

const int MAX = 2e5+10;
const int INF = 1LL<<60;
 
vector<vector<ii>> ns;
vi dirI = {0,1,0,-1};
vi dirJ = {1,0,-1,0};

enum {
    UP, DOWN, LEFT, RIGHT
};

int dist[MAX][4][4];
int djkstra(int s, int n, int end) {
	f(i,0,n+1){
        f(j,0,4){
            f(k,0,4){
                dist[i][j][k] = INF;
            }
        }
	}

    priority_queue<iiii, vector<iiii>, greater<iiii>> pq;
    f(i,0,4){
        dist[s][i][1] = 0;
        iiii temp = {dist[s][0][1], 1, i, s};
        pq.push(temp);
    }
 
    while(!pq.empty()) {
        auto [peso,quant,dir,node] = pq.top(); pq.pop();        
        if(peso > dist[node][dir][quant]) continue;

        int nxt_peso = peso+1;
        for(auto [nxt_node, nxt_dir] : ns[node]) {
            if(dir==nxt_dir){
                if(quant<3 and nxt_peso<dist[nxt_node][nxt_dir][quant+1]){
                    dist[nxt_node][nxt_dir][quant+1] = nxt_peso;
                    
                    iiii temp{nxt_peso, quant+1, nxt_dir, nxt_node};
                    pq.emplace(temp);
                }
            }
            else{
                if(nxt_peso<dist[nxt_node][nxt_dir][1]){
                    dist[nxt_node][nxt_dir][1] = nxt_peso;

                    iiii temp{nxt_peso, 1, nxt_dir, nxt_node};
                    pq.emplace(temp);
                }
            }
        }
    }

    int melhor=INF;
    f(i,0,4){
        f(j,0,4){
            melhor=min(melhor, dist[end][i][j]);
        }
    }
    return melhor!=INF ? melhor : -1;
}

void solve() {
    int n, m; cin >> n >> m;
    vector<string> mat(n);

    f(i,0,n){
        cin >> mat[i];
    }

    auto conv = [&](int i, int j) -> int {
        return i*m+j;
    };

    int tam = n*m;
    ns.assign(tam+2, vector<ii>());

    int pos_start=-1;
    int pos_end=-1;
    f(i,1,n-1){
        f(j,1,m-1){
            int cur = conv(i,j);

            f(k,0,4){
                int nxtI = i+dirI[k];
                int nxtJ = j+dirJ[k];

                if(mat[nxtI][nxtJ] != '#'){
                    ns[cur].pb({conv(nxtI, nxtJ),k});
                }
            }

            if(mat[i][j]=='S'){
                pos_start = conv(i,j);
            }
            if(mat[i][j]=='T'){
                pos_end = conv(i,j);
            }
        }
    }

    int x = djkstra(pos_start, tam+1, pos_end);
    std::cout << x << "\n";
}

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(nullptr);
    int tc = 1;
    if (all_test) cin >> tc;
    while (tc--) solve();
    return 0;
}