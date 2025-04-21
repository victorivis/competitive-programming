/*
https://leetcode.com/problems/bitwise-and-of-numbers-range/description/?envType=study-plan-v2&envId=top-interview-150
*/

class Solution {
    public:
        int rangeBitwiseAnd(int left, int right) {
            int total=0;
            for(int i=30; i>=0; i--){
               int a = (left>>i)&1;
               int b = (right>>i)&1;
                if(a&&b){
                    total += 1<<i;
                }
                else if(a||b)
                    break;
            }
    
            return total;
        }
};