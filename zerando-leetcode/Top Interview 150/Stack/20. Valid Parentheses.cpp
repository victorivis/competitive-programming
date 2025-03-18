/*
https://leetcode.com/problems/valid-parentheses/?envType=study-plan-v2&envId=top-interview-150
*/

class Solution {
public:
    bool isValid(string s) {
        stack<char> pilha;

        for(char i : s){
            if(i=='(' || i=='[' || i=='{'){
                pilha.push(i);
            }
            else{
                if(pilha.empty()){
                    return false;
                }
                if(i==')' && pilha.top()!='('){
                    return false;
                }
                if(i==']' && pilha.top()!='['){
                    return false;
                }
                if(i=='}' && pilha.top()!='{'){
                    return false;
                }
                pilha.pop();
            }
        }
        if(pilha.empty() == false){
            return false;
        }
        return true;
    }
};