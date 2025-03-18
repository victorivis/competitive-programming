/*
https://leetcode.com/problems/jump-game/?envType=study-plan-v2&envId=top-interview-150
*/

class Solution {
public:
    deque<int> getThere(vector<int>& nums, int n){
        deque<int> lista;

        for(int i=0; i<n; i++){
            if(i + nums[i] >= n){
                lista.push_back(i);
            }
        }
        return lista;
    }

    bool canJump(vector<int>& nums) {
        vector<bool> pode(nums.size(), false);
        pode[nums.size()-1]=true;
        deque<int> resultados = getThere(nums, nums.size()-1);
        for(int i=0; i<resultados.size(); i++){
            pode[resultados[i]]=true;
        }
        
        while(resultados.empty()==false && pode[0]==false){
            int atual=resultados[0];
            resultados.pop_front();
            
            deque<int> novosNumeros=getThere(nums, atual);
            
            for(int i=0; i<novosNumeros.size(); i++){
                if(pode[novosNumeros[i]]==false){
                    resultados.push_back(novosNumeros[i]);
                    pode[novosNumeros[i]]=true;
                }
            }
        }

        return pode[0];
    }
};