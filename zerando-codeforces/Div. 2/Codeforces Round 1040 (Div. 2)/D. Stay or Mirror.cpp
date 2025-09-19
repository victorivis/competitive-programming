/* https://codeforces.com/contest/2130/problem/D */

#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#define pbds                                               \
    tree<pair<int, int>, null_type, less<pair<int, int> >, \
         rb_tree_tag, tree_order_statistics_node_update>
using namespace __gnu_pbds;
using namespace std;

vector<int> countSmallerRight(int arr[], int n){
    pbds s;
    vector<int> ans;
    for (int i = n - 1; i >= 0; i--) {
        if (i == n - 1) {
            ans.push_back(0);
        }
        else {
            ans.push_back(s.order_of_key({ arr[i], i }));
        }
        s.insert({ arr[i], i });
    }

    reverse(ans.begin(), ans.end());
    
    return ans;
}

vector<int> countSmallerLeft(int arr[], int n){
    reverse(arr, &arr[n]);
    pbds s;
    vector<int> ans;
    for (int i = n - 1; i >= 0; i--) {
        if (i == n - 1) {
            ans.push_back(0);
        }
        else {
            ans.push_back(s.order_of_key({ arr[i], i }));
        }
        s.insert({ arr[i], i });
    }
    
    return ans;
}

void mostrar(vector<int>& lista){
    for(int num: lista){
        cout << num << " ";
    }
    cout << "\n";
}

int main(){
    int t; cin >> t;
    while(t--){
        int n; cin >> n;
        int lista[n];
        for(int i=0; i<n; i++){
            cin >> lista[i];
        }
        
        long long total=0;
        
        vector<int> smallRight = countSmallerRight(lista, n);
        vector<int> bigLeft = countSmallerLeft(lista, n);
        for(int i=0; i<n; i++){
            bigLeft[i] = i - bigLeft[i];
        }
        
        for(int i=0; i<n; i++){
            total+=min(bigLeft[i], (n - i -1 - smallRight[i]));
        }
        
        cout << total << "\n";
    }
    return 0;
}