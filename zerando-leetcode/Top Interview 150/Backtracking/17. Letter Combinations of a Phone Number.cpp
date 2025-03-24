/*
https://leetcode.com/problems/letter-combinations-of-a-phone-number/submissions/1584952319/?envType=study-plan-v2&envId=top-interview-150
*/

class Solution {
    private:
        vector<string> values;
    
    public:
        void combination(vector<string>& allStrings, string curr, string& digits){
            if(curr.size() == digits.size()){
                allStrings.push_back(curr);
            }
            else{
                int pos = curr.size();
                curr.push_back(' ');
    
                int posValues = digits[pos] - '2';
    
                cout << digits[pos] << " " << posValues << " " << values[posValues] << "\n";
    
                for(int i=0; i<values[posValues].size(); i++){
                    curr[pos] = values[posValues][i];
                    combination(allStrings, curr, digits);
                }
            }
        }
    
        vector<string> letterCombinations(string digits) {
            int numDigits=9;
    
            char caractereAtual = 'a';
            values.assign(numDigits, "");
    
            values = {
                "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"
            };
    
            vector<string> allStrings;
            if(digits==""){
                return allStrings;
            }
            combination(allStrings, "", digits);
    
            return allStrings;
        }
};