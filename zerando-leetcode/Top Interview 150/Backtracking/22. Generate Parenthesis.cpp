/*
https://leetcode.com/problems/generate-parentheses/?envType=study-plan-v2&envId=top-interview-150
*/

class Solution {
public:
    void gerador(string s, int tam, int abertos, int fechados, vector<string>& resposta){
        if(s.size()==2*tam){
            resposta.push_back(s);
        }
        else{
            if(abertos < tam){
                gerador(s+"(", tam, abertos+1, fechados, resposta);
                
            }
            if(abertos-fechados > 0){
                gerador(s+")", tam, abertos, fechados+1, resposta);
            }
        }
    }

    vector<string> generateParenthesis(int n) {
        vector<string> resposta;
        gerador("(", n, 1, 0, resposta);
        return resposta;
    }
};