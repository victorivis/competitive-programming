/*
https://leetcode.com/problems/max-points-on-a-line/submissions/1528793582/?envType=study-plan-v2&envId=top-interview-150
*/

class Solution {
public:
    const long long INF = INT_MAX;

    typedef struct{
        int x;
        int y;
    } par;

    int mdc(int a, int b){
        if(a==0 || b==0) return a+b;
        return mdc(b, a%b);
    }

    double lineAngle(par& p1, par& p2){
        double num = p1.x - p2.x;
        int den = p1.y - p2.y;
        
        return den==0 ? INT_MAX : num/den;
    }

    int maxPoints(vector<vector<int>>& points) {
        
        int maior=1;
        for(int i=0; i<points.size(); i++){
            for(int j=i+1; j<points.size(); j++){
                par p1 = {points[i][0], points[i][1]};
                par p2 = {points[j][0], points[j][1]};
                
                double angle = lineAngle(p1, p2);
                int atual=2;
                
                for(int k=j+1; k<points.size(); k++){
                    par p3 = {points[k][0], points[k][1]};
                    if(lineAngle(p1, p3) == angle){
                        atual++;
                    }
                }
                
                maior = max(atual, maior);
            }
        }
        
        return maior;
    }
};