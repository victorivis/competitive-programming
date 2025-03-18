/*
https://leetcode.com/problems/sqrtx/description/?envType=study-plan-v2&envId=top-interview-150
*/

//Metodo de aproximacao de Newton, onde correcao tende a zero
class Solution {
public:
    int mySqrt(int x) {
        double raiz = x;
        double correcao=1; //Nao iniciar vazio
        
        while(abs(correcao) > 0.01 && raiz!=0){
            correcao = (x - raiz*raiz)/(2*raiz);
            raiz += correcao;
        }

        return (int) raiz;
    }
};