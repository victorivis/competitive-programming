/*
https://leetcode.com/problems/maximum-sum-circular-subarray/?envType=study-plan-v2&envId=top-interview-150
*/

class Solution {
public:
    int kadene(int pos, vector<int>& nums){
        int total=nums[pos];
        int maior=nums[pos];

        int tam = nums.size();
        int cont=pos+1;
        while(cont < pos+tam){
            int pos = cont%tam;
            total = max(nums[pos], total+nums[pos]);
            maior = max(total, maior);

            cont++;
        }

        return maior;
    }

    int maxSubarraySumCircular(vector<int>& nums) {
        int melhor = kadene(0, nums);
        cout << melhor << "\n";

        for(int i=1; i<nums.size(); i++){
            if(nums[i]>=0 && nums[i-1]<0){
                int atual = kadene(i, nums);
                cout << atual << "\n";
                melhor = max(atual, melhor);
            }
        }

        return melhor;
    }
};