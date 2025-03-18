/*
https://leetcode.com/problems/factorial-trailing-zeroes/?envType=study-plan-v2&envId=top-interview-150
*/

class Solution {
public:
    int trailingZeroes(int n) {
        int  pow2=2;
        int  pow5=5;
        
        int  num2=0;
        int  num5=0;

        while(n>=pow2){
            num2 += n/pow2;
            pow2 *= 2;
        }

        while(n>=pow5){
            num5 += n/pow5;
            pow5 *= 5;
        }

        return min(num5, num2);
    }
};