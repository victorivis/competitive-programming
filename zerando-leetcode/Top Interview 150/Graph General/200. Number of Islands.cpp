/*
https://leetcode.com/problems/number-of-islands/description/?envType=study-plan-v2&envId=top-interview-150
*/

class Solution {
    private:
        int n, m;
        vector<vector<bool>> vis;
    
    public:
        bool isValid(int i, int j){
            if(i>=0 && i<n && j>=0 && j<m){
                return true;
            }
            return false;
        }
    
        void dfs(int x, int y, vector<vector<char>>& grid){
            static int dirJ[] = {0, 1, 0, -1};
            static int dirI[] = {1, 0, -1, 0};
            const int directions=4;
            vis[x][y]=true;
    
            for(int d=0; d<directions; d++){
                int i = x+dirI[d];
                int j = y+dirJ[d];
    
                if(isValid(i, j) && grid[i][j]=='1' && vis[i][j]==false){
                    dfs(i, j, grid);
                }
            }
        }
    
        int numIslands(vector<vector<char>>& grid) {
            n=grid.size();
            m=grid[0].size();
    
            vis.assign(n, vector<bool>(m, false));
    
            int total=0;
            for(int i=0; i<n; i++){
                for(int j=0; j<m; j++){
                    if(grid[i][j]=='1' && vis[i][j]==false){
                        dfs(i, j, grid);
                        total++;
                    }
                }
            }
    
            return total;
        }
};