/*
https://leetcode.com/problems/edit-distance/submissions/1425844101/?envType=study-plan-v2&envId=top-interview-150
*/

class Solution {
public:
    int minDistance(string word1, string word2) {
        if(word1.size() < word2.size()){
            string temp = word1;
            word1 = word2;
            word2 = temp;
        }

        int m=word1.size(), n=word2.size();

        vector<vector<int>> matriz(m+1, vector<int>(n+1, 0));
        for(int i=1; i<m+1; i++){
            matriz[i][0] = matriz[i-1][0] + 1;
        }

        for(int i=1; i<n+1; i++){
            matriz[0][i] = matriz[0][i-1] + 1;
        }
        
        int contador=10;
        for(int i=1; i<m+1; i++){
            for(int j=1; j<n+1; j++){
                //matriz[i][j] = contador++;
                
                int gapColuna = matriz[i-1][j]+1;
                int gapLinha = matriz[i][j-1]+1;
                int diagonal = matriz[i-1][j-1] + (word1[i-1] == word2[j-1] ? 0 : 1);
                
                int minimo = min(gapColuna, gapLinha);
                
                matriz[i][j] = min(diagonal, minimo);
            }
        }
        
        //mostrar(matriz);
        
        return matriz[m][n];
    }
};