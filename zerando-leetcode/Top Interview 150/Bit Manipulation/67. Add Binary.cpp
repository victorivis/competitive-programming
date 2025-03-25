/*
https://leetcode.com/problems/add-binary/?envType=study-plan-v2&envId=top-interview-150
*/

class Solution {
    public:
        void sumLogic(string& curr, char sum, bool& carryBit){
            if(sum=='1'){
                if(curr[0]=='1'){
                    curr[0]='0';
                    carryBit=true;
                }
                else{
                    curr[0]='1';
                }
            }
        }
    
        string addBinary(string a, string b) {
            string ans = "";
    
            int lower = min(a.size(), b.size());
            int upper = max(a.size(), b.size());
    
            int backA = a.size()-1;
            int backB = b.size()-1;
    
            bool carryBit;
            while(upper--){
                string s="0";
    
                if(carryBit){
                    carryBit=false;
                    sumLogic(s,'1',carryBit);
                }
    
                if(backA>=0){
                    sumLogic(s,a[backA--],carryBit);
                }
    
                if(backB>=0){
                    sumLogic(s,b[backB--],carryBit);
                }
    
                ans = s+ans;
            }
    
            if(carryBit){
                ans = "1"+ans;
            }
            return ans;
        }
};