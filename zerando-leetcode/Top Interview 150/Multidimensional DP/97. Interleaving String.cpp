/*
https://leetcode.com/problems/interleaving-string/description/?envType=study-plan-v2&envId=top-interview-150
*/

class Solution {
    public:
        bool isInterleave(string s1, string s2, string s3) {
            int n = s1.size(), m=s2.size();
            if(s3.size() != n+m){
                return false;
            }
    
            vector<vector<bool>> matriz(n+1, vector<bool>(m+1, true));
    
            for(int i=0; i<n+1; i++){
                for(int j=0; j<m+1; j++){
                    if(i==0 && j==0) continue;
    
                    int pos = i+j-1;
                    if(i-1>=0 && matriz[i-1][j] && s1[i-1]==s3[pos]){
                        matriz[i][j]=true;
                        continue;
                    }
                    
                    if(j-1>=0 && matriz[i][j-1] && s2[j-1]==s3[pos]){
                        matriz[i][j]=true;
                        continue;
                    }
                    matriz[i][j]=false;
                }
            }
    
            return matriz[n][m];
        }
};