/*
https://leetcode.com/problems/minimum-number-of-arrows-to-burst-balloons/description/?envType=study-plan-v2&envId=top-interview-150
*/

class Solution {
public:
    bool intersecta(vector<int>& a, vector<int>& b){
        if(a[0]<=b[0] && a[1]>=b[0]) return true;
        if(b[0]<=a[0] && b[1]>=a[0]) return true;
        return false;
    }

    int findMinArrowShots(vector<vector<int>>& points) {
        sort(points.begin(), points.end());
        
        vector<int> atual=points[0];
        int total=1;
        for(int i=1; i<points.size(); i++){
            if(intersecta(atual, points[i])){
                atual[0] = max(atual[0], points[i][0]);
                atual[1] = min(atual[1], points[i][1]);
            }
            else{
                total++;
                atual = points[i];
            }
        }

        return total;
    }
};