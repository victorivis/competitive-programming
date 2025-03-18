/*
https://leetcode.com/problems/word-break/?envType=study-plan-v2&envId=top-interview-150
*/

class Solution {
public:
    bool verificao(string s, map<string, bool>& dicionario){
        if(dicionario.count(s)!=0){
            return dicionario[s];
        }
        
        int limite = 19 < s.size() ? 19 : s.size();
        for(int i=1; i<limite; i++){
            string a = s.substr(0, i);
            string b = s.substr(i);
            if(verificao(a, dicionario) && verificao(b, dicionario)){
                dicionario[a]=true;
                dicionario[b]=true;
                return true;
            }
        }

        dicionario[s]=false;
        return false;
    }

    bool wordBreak(string s, vector<string>& wordDict) {
        map<string, bool> dicionario;
        for(string& palavra: wordDict){
            dicionario[palavra]=true;
        }
        
        return verificao(s, dicionario);
    }
};