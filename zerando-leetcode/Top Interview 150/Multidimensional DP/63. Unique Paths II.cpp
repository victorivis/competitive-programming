/*
https://leetcode.com/problems/unique-paths-ii/description/?envType=study-plan-v2&envId=top-interview-150
*/

class Solution {
public:
    int path(vector<vector<int>>& obG, int m, int n, map<pair<int, int>, int>& dicionario) {
        pair<int, int> par(m, n);

        if(dicionario.count(par) == 0) {
            int total = 0;
            if(m > 0 && obG[m-1][n] == 0) total += path(obG, m-1, n, dicionario);
            if(n > 0 && obG[m][n-1] == 0) total += path(obG, m, n-1, dicionario);
            dicionario[par] = total;
        }

        return dicionario[par];
    }

    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int m = obstacleGrid.size() - 1, n = obstacleGrid[0].size() - 1;

        if(obstacleGrid[0][0] == 1 || obstacleGrid[m][n] == 1) {
            return 0;
        }

        map<pair<int, int>, int> dicionario = {{{0, 0}, 1}};
        return path(obstacleGrid, m, n, dicionario);
    }
};