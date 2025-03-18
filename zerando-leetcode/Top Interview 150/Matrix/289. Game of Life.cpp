/*
https://leetcode.com/problems/game-of-life/description/?envType=study-plan-v2&envId=top-interview-150
*/

class Solution {
public:
    int verifyNeighboors(vector<vector<int>>& board, int i, int j){
        int total=0;
        if(i-1 >= 0) total+=board[i-1][j];
        if(j-1 >= 0) total+=board[i][j-1];
        if(j+1<board[i].size()) total+=board[i][j+1];
        if(i+1<board.size()) total+=board[i+1][j];

        if(i-1 >= 0 && j+1<board[i].size()) total+=board[i-1][j+1];
        if(i-1 >= 0 && j-1 >= 0) total+=board[i-1][j-1];
        if(i+1<board.size() && j+1<board[i].size()) total+=board[i+1][j+1];
        if(i+1<board.size() && j-1 >= 0) total+=board[i+1][j-1];

        return total;
    }

    void gameOfLife(vector<vector<int>>& board) {
        vector<vector<int>> backup = board;

        for(int i=0; i<board.size(); i++){
            for(int j=0; j<board[i].size(); j++){
                int current = backup[i][j];

                int aliveNeighboors = verifyNeighboors(backup, i, j);
                if(current==0 && aliveNeighboors==3){
                    board[i][j]=1;
                }

                if(current==1 && (aliveNeighboors>3 || aliveNeighboors<2)){
                    board[i][j]=0;
                }
            }
        }
    }
};