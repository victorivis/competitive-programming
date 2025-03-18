/*
https://leetcode.com/problems/rotate-array/?envType=study-plan-v2&envId=top-interview-150
*/

class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        int tam = nums.size();
        vector<int> copia = nums;

        k = k%tam;

        for(int i=0; i<tam; i++){
            nums[(i+k)%tam] = copia[i];
        }
    }
};