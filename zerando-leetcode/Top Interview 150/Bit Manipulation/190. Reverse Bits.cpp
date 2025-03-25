/*
https://leetcode.com/problems/reverse-bits/description/?envType=study-plan-v2&envId=top-interview-150
*/

class Solution {
    public:
        uint32_t reverseBits(uint32_t n) {
            uint32_t saida = 0;
    
            for(int i=31; i>=0; i--){
                saida |= (n&1)<<i;
                n>>=1;
            }
    
            return saida;
        }
};