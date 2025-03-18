/*
https://leetcode.com/problems/two-sum-ii-input-array-is-sorted/submissions/1530196589/
*/

class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int tam = numbers.size();
        int l=0, r=tam-1;

        int soma=numbers[l]+numbers[r];
        while(soma!=target){
            if(soma>target) r--;
            else l++;
            soma = numbers[l]+numbers[r];
        }

        return vector<int>({l+1, r+1});
    }
};