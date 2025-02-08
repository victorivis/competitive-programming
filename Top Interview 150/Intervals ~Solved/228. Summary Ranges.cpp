/*
https://leetcode.com/problems/summary-ranges/description/?envType=study-plan-v2&envId=top-interview-150
*/

class Solution {
public:
    vector<string> summaryRanges(vector<int>& nums) {
        vector<string> resposta;

        if(nums.size()>0){
            int l=nums[0],r=nums[0];
            for(int i=1; i<nums.size(); i++){
                if(nums[i]>r+1){
                    if(l==r){
                        resposta.push_back(to_string(r));
                    }
                    else{
                        string temp = to_string(l) + "->" + to_string(r);
                        resposta.push_back(temp);
                    }

                    l=r=nums[i];
                }
                else{
                    r++;
                }
            }

            if(l==r){
                resposta.push_back(to_string(r));
            }
            else{
                resposta.push_back(to_string(l) + "->" + to_string(r));
            }
        }

        return resposta;
    }
};