/*
https://leetcode.com/problems/triangle/?envType=study-plan-v2&envId=top-interview-150
*/

class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        const int INF = INT_MAX;
        int tam = triangle.size();
        vector<vector<int>> dp(tam, vector<int>(tam, INF));

        dp[0][0] = triangle[0][0];

        for(int i=0; i<tam-1; i++){
            for(int j=0; j<=i; j++){
                dp[i+1][j] = min(dp[i+1][j], dp[i][j] + triangle[i+1][j]);
                dp[i+1][j+1] = min(dp[i+1][j+1], dp[i][j] + triangle[i+1][j+1]);
            }
        }

        int menor = INF;
        for(int j=0; j<tam; j++){
            menor = min(menor, dp[tam-1][j]);
        }
        return menor;
    }
};