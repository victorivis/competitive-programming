/*
https://leetcode.com/problems/group-anagrams/description/?envType=study-plan-v2&envId=top-interview-150
*/

class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        int cont=0;

        vector<vector<string>> resultado;
        unordered_map<string, int> d;
        
        for(int i=0; i<strs.size(); i++){
            string s = strs[i];
            sort(s.begin(), s.end());

            if(d.count(s)==0){
                d[s]=cont++;
                resultado.push_back(vector<string>(1, strs[i]));
            }
            else{
                int pos = d[s];
                resultado[pos].push_back(strs[i]);
            }
        }

        return resultado;
    }
};