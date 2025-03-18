/*
https://leetcode.com/problems/remove-duplicates-from-sorted-array/?envType=study-plan-v2&envId=top-interview-150
*/

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int esquerda=0, direita=1;
        bool distanciado=false;

        while(direita!=nums.size()){
            if(nums[esquerda] == nums[direita]){
                distanciado=true;
            }
            else{
                esquerda++;
                if(distanciado){
                    nums[esquerda] = nums[direita];
                }
            }
            direita++;
        }

        return esquerda+1;
    }
};