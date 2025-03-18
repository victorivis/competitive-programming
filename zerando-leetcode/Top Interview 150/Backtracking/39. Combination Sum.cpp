/*
https://leetcode.com/problems/combination-sum/?envType=study-plan-v2&envId=top-interview-150
*/

class Solution {
public:
    void backtrack(vector<vector<int>>& destino, vector<int>& opcoes, vector<int>& atual, int objetivo, int pos){
        if(objetivo==0){
            destino.push_back(atual);
        }
        else if(objetivo>0){
            for(int i=pos; i<opcoes.size() && objetivo-opcoes[i]>=0; i++){
                atual.push_back(opcoes[i]);
                backtrack(destino, opcoes, atual, objetivo - opcoes[i], i);
                atual.pop_back();
            }
        }
    }

    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> destino;
        vector<int> atual;

        sort(candidates.begin(), candidates.end());

        backtrack(destino, candidates, atual, target, 0);

        return destino;
    }
};