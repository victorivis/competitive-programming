/*
https://leetcode.com/problems/word-ladder/description/?envType=study-plan-v2&envId=top-interview-150
*/

class Solution {
    public:
        int distancia(string& a, string& b){
            int menor = min(a.size(), b.size());
            int maior = max(a.size(), b.size());
            int total = maior - menor;
    
            for(int i=0; i<menor; i++){
                if(a[i] != b[i]){
                    total++;
                }
            }
    
            return total;
        }
    
        int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
            unordered_map<string, vector<string>> grafo;
    
            wordList.push_back(beginWord);
            for(int i=0; i<wordList.size(); i++){
                for(int j=i+1; j<wordList.size(); j++){
                    if(distancia(wordList[i], wordList[j])==1){
                        grafo[wordList[i]].push_back(wordList[j]);
                        grafo[wordList[j]].push_back(wordList[i]);
                    }
                }
            }
    
            unordered_map<string, bool> visitados;
    
            queue<pair<string, int>> fila;
            fila.push(pair<string, int>(beginWord, 0));
            visitados[beginWord]=true;
    
            while(fila.empty()==false){
                string atual = fila.front().first;
                int dist = fila.front().second;            
                fila.pop();
    
                if(atual==endWord){
                    return dist+1;
                }
    
                for(string& s: grafo[atual]){
                    if(visitados[s]==false){
                        visitados[s]=true;
                        fila.push(pair<string, int>(s, dist+1));
                    }
                }
            }
            return 0;
        }
};