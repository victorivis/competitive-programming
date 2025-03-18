/*
https://leetcode.com/problems/plus-one/?envType=study-plan-v2&envId=top-interview-150
*/

class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int pos = (int) digits.size() - 1;
        while(pos>=0 && digits[pos] == 9){
            digits[pos]=0;
            pos--;
        }

        if(pos==-1){
            digits.push_back(0);
            digits[0]=1;
        }
        else{
            digits[pos]+=1;
        }
        return digits;
    }
};