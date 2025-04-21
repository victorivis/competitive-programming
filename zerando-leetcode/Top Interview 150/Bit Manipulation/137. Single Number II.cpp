/*
https://leetcode.com/problems/single-number-ii/description/?envType=study-plan-v2&envId=top-interview-150
*/

class Solution {
    public:
        int singleNumber(vector<int>& nums) {
            int ehDois=0;
            int ehUm=0;
    
            for(int i=0; i<nums.size(); i++){
                int temp = ehDois;
                ehDois ^= ehUm & nums[i];
                ehUm ^= ~ehDois & nums[i];
            }
    
            return ehUm;
        }
};