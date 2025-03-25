/*
https://leetcode.com/problems/spiral-matrix/?envType=study-plan-v2&envId=top-interview-150
*/

class Solution {
    private:
        int lower;
        int n, m;
    public:
        void layer(int pos, vector<vector<int>>& matrix , vector<int>& ans){
            for(int j=pos; j<m-pos; j++){
                ans.push_back(matrix[pos][j]);
            }
    
            for(int i=pos+1; i<n-pos; i++){
                ans.push_back(matrix[i][m-pos-1]);
            }
    
            if(2*pos+1!=lower){            
                for(int j=m-pos-2; j>=pos; j--){
                    ans.push_back(matrix[n-pos-1][j]);
                }
    
                for(int i=n-pos-2; i>pos; i--){
                    cout << i << " ";
                    ans.push_back(matrix[i][pos]);
                }
            }
        }
    
        vector<int> spiralOrder(vector<vector<int>>& matrix) {
            n=matrix.size();
            m=matrix[0].size();
            lower=min(n, m);
    
            vector<int> ans;
            for(int i=0; i<(lower+1)/2; i++){
                layer(i, matrix, ans);
            }
            return ans;
        }
};