/*
https://leetcode.com/problems/house-robber/description/?envType=study-plan-v2&envId=top-interview-150
*/

class Solution {
private:
    int tam;

public:
    void path(vector<int>& nums, vector<int>& dp, int n){
        if(n+2<tam){
            dp[n+2] = max(dp[n+2], dp[n] + nums[n+2]);
        }
        if(n+3<tam){
            dp[n+3] = max(dp[n+3], dp[n] + nums[n+3]);
        }
    }

    int rob(vector<int>& nums) {
        tam = nums.size();

        vector<int> dp(tam);
        for(int i=0; i<tam; i++){
            dp[i]=nums[i];
        }

        int maior=0;
        for(int i=0; i<tam; i++){
            if(dp[i]!=0){
                path(nums, dp, i);
                maior = max(maior, dp[i]);
            }
        }

        return maior;
    }
};