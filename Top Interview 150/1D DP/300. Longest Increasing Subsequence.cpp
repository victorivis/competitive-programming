/*
https://leetcode.com/problems/longest-increasing-subsequence/description/?envType=study-plan-v2&envId=top-interview-150
*/

class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int tam = nums.size();
        
        int maior=0;
        
        vector<int> memo(tam, -1);
        for(int i=tam-1; i>=0; i--){
            memo[i]=1;

            for(int j=i+1; j<tam; j++){
                if(nums[i] < nums[j]){
                    memo[i] = max(memo[i], memo[j]+1);
                }
            }
            maior = max(maior, memo[i]);
        }

        return maior;
    }
};