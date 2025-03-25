/*
https://leetcode.com/problems/remove-element/description/?envType=study-plan-v2&envId=top-interview-150
*/

class Solution {
    public:
        int removeElement(vector<int>& nums, int val) {
            int numPos=0;
    
            for(int i=0; i<nums.size(); i++){
                if(nums[i]==val){
                    numPos++;
                }
                else{
                    if(numPos>0){
                        swap(nums[i], nums[i-numPos]);
                    }
                }
            }
    
            return nums.size() - numPos;
        }
};