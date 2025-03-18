/*
https://leetcode.com/problems/merge-intervals/description/?envType=study-plan-v2&envId=top-interview-150
*/

class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end());
        
        vector<vector<int>> resposta;
        int p=0;
        for(int i=0; i<intervals.size(); i++){
            bool mesclado=false;
            while(p<resposta.size()){
                if(resposta[p][1] >= intervals[i][0]){
                    resposta[p][1] = max(resposta[p][1], intervals[i][1]);
                    mesclado=true;
                    break;
                }
                else{
                    p++;
                }
            }

            if(mesclado==false) resposta.push_back(intervals[i]);
        }

        return resposta;
    }
};