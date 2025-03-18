/*
https://leetcode.com/problems/integer-to-roman/?envType=study-plan-v2&envId=top-interview-150
*/

class Solution {
public:
    string intToRoman(int num) {
        vector<int> digitos;

        while(num!=0){
            digitos.push_back(num%10);
            num/=10;
        }

        string algarismos = "IVXLCDM";

        int tam = digitos.size();
        string resposta="";
        for(int i=tam-1; i>=0; i--){
            int menor = i*2;
            int maior = i*2+1;
            
            //printf("{%d, %d}, %d\n", menor, maior, i);
            
            if(digitos[i]>=5 && digitos[i]<9){
                resposta+=algarismos[maior];
            }
            if(digitos[i]%5<=3){
                for(int j=0; j<digitos[i]%5; j++){
                    resposta += algarismos[menor];
                }
            }
            if(digitos[i]==4){
                resposta += algarismos[menor];
                resposta += algarismos[maior];
            }
            if(digitos[i]==9){
                resposta += algarismos[menor];
                resposta += algarismos[maior+1];
            }
        }

        return resposta;
    }
};