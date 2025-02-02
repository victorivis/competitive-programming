/*
https://leetcode.com/problems/two-sum/description/?envType=study-plan-v2&envId=top-interview-150
*/

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        map<int, int> hashMap;
        vector<int> resposta(2);

        for(int i=0; i<nums.size(); i++){
            if(hashMap.find(target-nums[i]) != hashMap.end()){
                
                resposta[0]=i;
                resposta[1]= hashMap[target-nums[i]];
                return resposta;
            }
            hashMap[nums[i]]=i;
        }

        return resposta;
    }
};