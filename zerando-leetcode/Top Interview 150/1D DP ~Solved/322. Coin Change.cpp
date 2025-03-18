/*
https://leetcode.com/problems/coin-change/description/?envType=study-plan-v2&envId=top-interview-150
*/

class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        vector<int> lista(amount+1, -1);
        queue<int> p;
        lista[0] = 0;
        p.push(0);

        while(p.empty()==false){
            long long atual=p.front();
            p.pop();

            for(int i=0; i<coins.size(); i++){
                long long gerado=atual+coins[i];
                if(gerado < lista.size() && lista[gerado]==-1){
                    lista[gerado]=1+lista[atual];
                    p.push(gerado);
                }
            }
        }

        return lista[amount];
    }
};