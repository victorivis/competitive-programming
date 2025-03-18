/*
https://leetcode.com/problems/longest-palindromic-substring/submissions/1422049569/?envType=study-plan-v2&envId=top-interview-150
*/

class Solution {
public:
    string longestPalindrome(string s) {
        vector<pair<int, int>> lista(s.size());
        
        int maior;
        pair<int, int>* ideal;
        
        for(int i=0; i<s.size(); i++){
            lista[i] = pair<int, int>(i, 1);
            if(i!=s.size()-1 && s[i]==s[i+1]){
                lista.push_back(pair<int, int>(i, 2));
            }
        }
        
        if(lista.size() == s.size()){ 
            maior=1, ideal=&lista[0];
        }
        else{
            maior=2, ideal=&lista[s.size()];
        }
        
        
        for(int i=0; i<lista.size(); i++){
            while(lista[i].first>0 && lista[i].second<s.size()){
                int a=lista[i].first;
                int b=lista[i].second;

                if(s[a-1] == s[a+b]){
                    lista[i] = pair<int, int>(a-1, b+2);
                    if(maior < b+2){
                        maior=b+2;
                        ideal=&lista[i];
                    }
                }
                else{
                    break;
                }
            }
        }
        
        string resposta="";
        for(int i=ideal->first; i<ideal->first + ideal->second; i++){
            resposta.push_back(s[i]);
        }
        
        return resposta;
    }
};