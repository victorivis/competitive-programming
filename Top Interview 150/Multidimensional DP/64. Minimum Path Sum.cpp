/*
https://leetcode.com/problems/minimum-path-sum/submissions/1425409693/?envType=study-plan-v2&envId=top-interview-150
*/

class Solution {
public:
    int path(vector<vector<int>>& g, map<pair<int, int>, int>& dict, int m, int n){
        pair<int, int> par(m, n);
        if(dict.count(par)==0){
            int atual = g[m][n];

            int a = m==0 ? INT_MAX : atual + path(g, dict, m-1, n);
            int b = n==0 ? INT_MAX : atual + path(g, dict, m, n-1);

            dict[par] = min(a, b);
        }
        return dict[par];
    }

    int minPathSum(vector<vector<int>>& grid) {
        map<pair<int, int>, int> dicionario={{{0, 0}, grid[0][0]}};
        int m=grid.size()-1, n=grid[0].size()-1;

        return path(grid, dicionario, m, n);
    }
};