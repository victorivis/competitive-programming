/*
https://leetcode.com/problems/text-justification/?envType=study-plan-v2&envId=top-interview-150
*/

class Solution {
public:
    vector<string> fullJustify(vector<string>& words, int maxWidth) {
        vector<string> resposta;

        int espaco=0;
        int inicio=0;
        for(int i=0; i<words.size(); i++){
            if(espaco==0){
                espaco = words[i].size();
                inicio = i;
            }
            else{
                if(espaco + words[i].size() + 1 <= maxWidth){
                    espaco += words[i].size()+1;
                }
                else{
                    int numPalavras = i-inicio;
                    int espacamento = maxWidth - espaco;

                    cout << numPalavras << " " << espacamento << " " << espaco << "\n";

                    string linha = words[inicio];
                    if(numPalavras==1) linha+= string(espacamento, ' ');
                    else{
                        int resto = espacamento % (numPalavras-1);
                        int divisao = espacamento / (numPalavras-1);

                        for(int j=inicio+1; j<i; j++){
                            int correcao=0;
                            if(resto>0){
                                correcao=1;
                                resto--;
                            }
                            
                            linha += string(divisao+1+correcao, ' ') + words[j];
                        }
                    }

                    resposta.push_back(linha);

                    i--;
                    espaco=0;
                }
            }
        }

        string ultimaLinha = words[inicio];
        for(int i=inicio+1; i<words.size(); i++){
            ultimaLinha += " " + words[i];
        }
        
        if(ultimaLinha.size() < maxWidth)
            ultimaLinha += string(maxWidth - (int) ultimaLinha.size(), ' ');
        
        resposta.push_back(ultimaLinha);

        return resposta;    
    }
};