/*
https://leetcode.com/problems/valid-sudoku/?envType=study-plan-v2&envId=top-interview-150
*/

class Solution {
public:
    bool validSquare(vector<vector<char>>& board, int x, int y){
        map<char, bool> dict;
        for(int i=x; i<x+3; i++){
            for(int j=y; j<y+3; j++){
                char atual = board[i][j];

                if(atual!='.'){
                    if(dict.count(atual)==0){
                        dict[atual]=true;
                    }
                    else{
                        return false;
                    }
                }
            }
        }

        return true;
    }

    bool validLine(vector<vector<char>>& board, int x, bool horizontal){
        map<char, bool> dict;

        for(int i=0; i<board.size(); i++){
            char atual = horizontal ? board[x][i] : board[i][x];

            if(atual!='.'){
                if(dict.count(atual)==0){
                    dict[atual]=true;
                }
                else{
                    return false;
                }
            }
        }

        return true;
    }

    bool isValidSudoku(vector<vector<char>>& board) {
        for(int i=0; i<board.size(); i+=3){
            for(int j=0; j<board[i].size(); j+=3){
                bool quadrado = validSquare(board, i, j);
                if(quadrado==false) return false;
            }
        }

        for(int i=0; i<board.size(); i++){
            bool horizontal = validLine(board, i, true);
            bool vertical = validLine(board, i, false);

            if((horizontal && vertical) == false){
                return false;
            }
        }

        return true;
    }
};