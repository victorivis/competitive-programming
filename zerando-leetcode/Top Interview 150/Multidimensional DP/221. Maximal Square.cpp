/*
https://leetcode.com/problems/maximal-square/description/?envType=study-plan-v2&envId=top-interview-150
*/

class Solution {
    public:
        int maximalSquare(vector<vector<char>>& matrix) {
            int n=matrix.size();
            int m=matrix[0].size();
            
            vector<vector<int>> dp(n, vector<int>(m, 0));
            int total=0;
    
            for(int i=0; i<dp.size(); i++){
                if(matrix[i][0]=='1'){
                    dp[i][0] = total = 1;
                }
            }
    
            for(int j=0; j<dp[0].size(); j++){
                if(matrix[0][j]=='1'){
                    dp[0][j] = total = 1;
                }
            }
    
            for(int i=1; i<n; i++){
                for(int j=1; j<m; j++){
                    if(matrix[i][j]=='1'){
                        int menor = min(dp[i-1][j], dp[i][j-1]);
                        dp[i][j] = 1+min(menor, dp[i-1][j-1]);
    
                        total = max(total, dp[i][j]);
                    }
                }
            }
    
            return total*total;
        }
};