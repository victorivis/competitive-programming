/*
https://leetcode.com/problems/surrounded-regions/description/?envType=study-plan-v2&envId=top-interview-150
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
    
        void dfs(int x, int y, vector<vector<char>>& grid, bool change){
            static int dirJ[] = {0, 1, 0, -1};
            static int dirI[] = {1, 0, -1, 0};
            const int directions=4;
            vis[x][y]=true;
            if(change) grid[x][y]='X';
    
            for(int d=0; d<directions; d++){
                int i = x+dirI[d];
                int j = y+dirJ[d];
    
                if(isValid(i, j) && grid[i][j]=='O' && vis[i][j]==false){
                    dfs(i, j, grid, change);
                }
            }
        }
    
        void solve(vector<vector<char>>& board) {
            n=board.size();
            m=board[0].size();
    
            vis.assign(n, vector<bool>(m, false));

            //Percorre as bordas
            int lastJ=m-1;
            int firstJ=0;
            for(int i=0; i<n; i++){
                if(board[i][lastJ]=='O' && vis[i][lastJ]==false){
                    dfs(i, lastJ, board, false);
                }

                if(board[i][firstJ]=='O' && vis[i][firstJ]==false){
                    dfs(i, firstJ, board, false);
                }
            }

            int firstI=0;
            int lastI=n-1;
            for(int j=1; j<m-1; j++){
                if(board[firstI][j]=='O' && vis[firstI][j]==false){
                    dfs(firstI, j, board, false);
                }

                if(board[lastI][j]=='O' && vis[lastI][j]==false){
                    dfs(lastI, j, board, false);
                }
            }

            //Captura as regioes
            for(int i=1; i<n-1; i++){
                for(int j=1; j<m-1; j++){
                    if(board[i][j]=='O' && vis[i][j]==false){
                        dfs(i, j, board, true);
                    }
                }
            }
        }
};