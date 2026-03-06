/* https://codeforces.com/contest/597/problem/C */

#include <bits/stdc++.h>
using namespace std;

using T = unsigned long long;
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
    
    void debug(){
        for(int i=0; i<=n; i++){
            cout << bit[i] << " ";
        }
        cout << "\n";
    }

    void add(int i, T v) {
        for (; i <= n; i += i & -i)
            bit[i] += v;
    }

    T sum(int i) {
        T s = 0;
        for (; i > 0; i -= i & -i)
            s += bit[i];
        return s;
    }
    
    int busca(int k){
        int l=0, r=n;
        while(l<r){
            int mid = (l + r) / 2;
            if (sum(mid) >= k){
                r = mid;
            }
            else{
                l = mid + 1;
            }
        }
        return l;
    }
    
    int kth(int k) {
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

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    
    int n, k; cin >> n >> k;
    k++;
    
    vector<T> li(n);
    for(int i=0; i<n; i++){
        cin >> li[i];
    }
    
    vector<Fenwick> bits(k+1, Fenwick(n+2));
    bits[0].add(1, 1);
    
    for(auto& p: li){
        for(int i=k; i>0; i--){
            T anterior = bits[i-1].sum(p);
            if(anterior>0){
                bits[i].add(p, anterior);
            }
        }
    }
    cout << bits[k].sum(n) << "\n";
    return 0;
}