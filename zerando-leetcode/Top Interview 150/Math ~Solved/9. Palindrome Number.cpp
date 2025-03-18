/*
https://leetcode.com/problems/palindrome-number/?envType=study-plan-v2&envId=top-interview-150
*/

class Solution {
public:
    bool isPalindrome(int x) {
        if(x<0){
            return false;
        }
        else{
            vector<int> digits;

            while(x!=0){
                digits.push_back(x%10);
                x/=10;
            }

            int tam=digits.size();

            for(int i=0; i<tam/2; i++){
                if(digits[i] != digits[tam-1-i]){
                    return false;
                }
            }
            
            return true;
        }
    }
};