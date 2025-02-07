/*
https://leetcode.com/problems/longest-substring-without-repeating-characters/description/?envType=study-plan-v2&envId=top-interview-150
*/

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int esq=0, dir=0;
        int maior=0;
        
        map<char, bool> dicionario;

        for(int i=0; i<s.size(); i++){
            dir=i;
            char letra = s[i];

            if(dicionario[letra]==false){
                dicionario[letra]=true;
            }
            else{
                while(dicionario[letra]==true){
                    dicionario[s[esq]]=false;
                    esq++;
                }
                
                dicionario[letra]=true;
            }

            maior = max(dir - esq + 1, maior);
        }

        return maior;
    }
};