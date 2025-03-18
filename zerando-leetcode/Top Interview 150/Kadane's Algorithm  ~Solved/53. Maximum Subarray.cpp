/*
https://leetcode.com/problems/maximum-subarray/description/?envType=study-plan-v2&envId=top-interview-150
*/

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int tamanho = nums.size();
        
        if(tamanho==1){
            return nums[0];
        }
        
        vector<int> prefixo(tamanho+1, 0);
        
        for(int i=1; i<=tamanho; i++){
            prefixo[i] = prefixo[i-1] + nums[i-1];
        }
        
        int menor[tamanho];
        int maior[tamanho];
        
        menor[0] = prefixo[1];
        maior[tamanho-1] = prefixo[tamanho];
        
        //mostrar(prefixo);
        
        for(int i=1; i<tamanho; i++){
            menor[i] = min(menor[i-1], prefixo[i+1]);
            maior[tamanho-i-1] = max(maior[tamanho-i], prefixo[tamanho-i]);
        }
        
        //mostrar(menor, tamanho);
        //mostrar(maior, tamanho);
        
        int resposta=prefixo[1];
        for(int i=0; i<tamanho-1; i++){
            resposta=max(resposta, maior[i+1]-menor[i]);
        }
        resposta = max(resposta, prefixo[tamanho]);
        
        return resposta;
    }
};
