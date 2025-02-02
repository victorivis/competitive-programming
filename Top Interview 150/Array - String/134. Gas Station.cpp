/*
https://leetcode.com/problems/gas-station/?envType=study-plan-v2&envId=top-interview-150
*/

class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int pos=0;
        int total=0;
        bool impossivel=false;

        for(int i=0; i<gas.size(); i++) total+=gas[i]-cost[i];
        if(total<0) return -1;

        total=0;
        for(int i=0; i<gas.size(); i++){
            total+=gas[i]-cost[i];

            if(total<0){
                pos=i+1;
                total=0;
            }
        }
        return pos;         
    }
};