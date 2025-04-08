/*
https://leetcode.com/problems/implement-trie-prefix-tree/description/?envType=study-plan-v2&envId=top-interview-150
*/

struct par{
    par* letras[26];
    bool completa;
    par(): completa(false), letras{nullptr}{
    }
};

class Trie {
private:
    par* letras;    

public:
    Trie() {
        letras = new par();
    }
    
    void insert(string word) {
        int i=0;

        par* temp = letras;
        while(i<word.size()){
            int pos = word[i]-'a';

            if((temp->letras)[pos] == nullptr){
                (temp->letras)[pos] = new par();
            }
            temp = (temp->letras)[pos];
            i++;
        }
        temp->completa=true;
    }
    
    bool search(string word) {
        int i=0;

        par* temp = letras;
        while(i<word.size()){
            int pos = static_cast<int>(word[i]-'a');
            if(temp->letras[pos] == nullptr){
                return false;
            }
            temp = temp->letras[pos];
            i++;
        }
        return temp->completa;
    }
    
    bool startsWith(string prefix) {
        int i=0;

        par* temp = letras;
        while(i<prefix.size()){
            int pos = static_cast<int>(prefix[i]-'a');
            if(temp->letras[pos] == NULL){
                return false;
            }
            temp = temp->letras[pos];
            i++;
        }
        return true;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */