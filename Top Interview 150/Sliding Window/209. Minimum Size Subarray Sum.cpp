/*
https://leetcode.com/problems/minimum-size-subarray-sum/description/
*/

class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int menor=INT_MAX;

        int l=0, r=0;
        int total=nums[0];
        while(r<nums.size()){
            if(total>=target){
                menor = min(menor, r-l+1);
            }
            if(total>=target && l<r){
                total-=nums[l];
                l++;
            }
            else{
                r++;
                if(r<nums.size()){
                    total+=nums[r];
                }
            }
        }

        return menor!=INT_MAX ? menor : 0;
    }
};