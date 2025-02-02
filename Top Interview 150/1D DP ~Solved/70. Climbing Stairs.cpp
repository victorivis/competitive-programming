/*
https://leetcode.com/problems/climbing-stairs/description/?envType=study-plan-v2&envId=top-interview-150
*/

class Solution {
public:
    int climbStairs(int n) {
            static vector<int> memoization(60, -1);
            if(memoization[0]==-1){
                memoization[0]=1;
                memoization[1]=1;
            }
            
            if(memoization[n]==-1){
                memoization[n] = climbStairs(n-1) + climbStairs(n-2);
                return memoization[n];
            }
            return memoization[n];
        }
};