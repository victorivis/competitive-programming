/*
https://leetcode.com/problems/best-time-to-buy-and-sell-stock-ii/description/?envType=study-plan-v2&envId=top-interview-150
*/

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int anterior=prices[0];
        int total=0;
        for(int i: prices){
            if(i>anterior){
                total+=i-anterior;
                anterior=i;
            }
            else{
                anterior=i;
            }
        }

        return total;
    }
};