/*
https://leetcode.com/problems/set-matrix-zeroes/description/?envType=study-plan-v2&envId=top-interview-150
*/

class Solution {
    public:
        void setZeroes(vector<vector<int>>& matrix) {
            vector<pair<int, int>> zerus;
    
            for(int i=0; i<matrix.size(); i++){
                for(int j=0; j<matrix[i].size(); j++){
                    if(matrix[i][j]==0){
                        zerus.push_back(pair<int, int>(i, j));
                    }
                }
            }
    
            for(pair<int, int>& p: zerus){
                //cout << p.first << " " << p.second << "\n";
                for(int j=0; j<matrix[0].size(); j++){
                    matrix[p.first][j]=0;
                }
    
                for(int i=0; i<matrix.size(); i++){
                    matrix[i][p.second]=0;
                }
            }
        }
    };