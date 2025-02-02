/*
https://leetcode.com/problems/powx-n/description/?envType=study-plan-v2&envId=top-interview-150
*/

class Solution {
public:
    double myPow(double x, int n) {
        if(n==0) return 1;

        double subproblema = myPow(x, n/2);
        double total = subproblema * subproblema;
        
        if(abs(n%2)==1){
            total*= n>0 ? x : (1/x);
        }

        return total;
    }
};