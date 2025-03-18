/*
https://leetcode.com/problems/trapping-rain-water/?envType=study-plan-v2&envId=top-interview-150
*/

class Solution {
public:
    int choveChuva(vector<int>& lista, int total, int minimo, int p1, int p2){
        if(p1==p2 || p1+1==p2){
            return total;
        }

        int novoMenor = min(lista[p1], lista[p2]);
        if(novoMenor > minimo){
            int novo = (p2-p1-1) * (novoMenor-minimo);

            if(novo>0){
                total+=novo;
            }
            minimo=novoMenor;
        }
        
        if(lista[p1] <= lista[p2]){
            int diferenca = lista[p1+1];
            total -= min(diferenca, minimo);
            return choveChuva(lista, total, minimo, p1+1, p2);
        }
        else{
            int diferenca = lista[p2-1];
            total -= min(diferenca, minimo);
            return choveChuva(lista, total, minimo, p1, p2-1);
        }
    }

    int trap(vector<int>& height) {
        if(height.size() <= 2){
            return 0;
        }
        else{
            int p1=0, p2=height.size()-1;
            return choveChuva(height, 0, 0, p1, p2);
        }
    }
};