/*
https://leetcode.com/problems/container-with-most-water/description/?envType=study-plan-v2&envId=top-interview-150
*/

class Solution {
public:
    int maxArea(vector<int>& height) {
        int maior_num = 0;
        int ponteiro_esquerda=0;
        int ponteiro_direita=height.size()-1;
        
        while(ponteiro_esquerda < ponteiro_direita){
            int menor = min(height[ponteiro_esquerda], height[ponteiro_direita]);
            int atual =  menor * abs(ponteiro_direita - ponteiro_esquerda);
            if(atual > maior_num){
                maior_num = atual;
            }
            
            if(menor == height[ponteiro_esquerda]){
                ponteiro_esquerda++;
            }
            else{
                ponteiro_direita--;
            }
        }
        
        return maior_num;
    }
};