class Solution {
public:
    void push(vector<vector<int>>& intervals, vector<int>& newInterval, int pos){
        intervals.push_back(newInterval);
        for(int i=intervals.size()-1; i>pos; i--){
            swap(intervals[i], intervals[i-1]);
        }
    }

    bool intersecta(vector<int>& a, vector<int>& b){
        if(a[0]<=b[0] && a[1]>=b[0]) return true;
        if(b[0]<=a[0] && b[1]>=a[0]) return true;
        return false;
    }

    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval){
        bool primeiroOverlap=true;
        
        int delL=-1, delR=-1;
        int primeiro=-1;
        int menor=-1;
        for(int i=0; i<intervals.size(); i++){
            bool houveOverlap = intersecta(newInterval, intervals[i]);
            if(intervals[i][0] < newInterval[0]){
                menor=i;
            }
            
            if(houveOverlap){
                if(primeiroOverlap){
                    primeiroOverlap=false;
                    primeiro = i;
                    delL = i+1;
                }
                else{
                    delR=i+1;
                }

                newInterval[0] = min(intervals[i][0], newInterval[0]);
                newInterval[1] = max(intervals[i][1], newInterval[1]);
            }
        }

        if(primeiroOverlap==false){
            if(delR!=-1){
                intervals.erase(intervals.begin()+delL, intervals.begin()+delR);
            }
            intervals[primeiro] = newInterval;
        }
        else{
            push(intervals, newInterval, menor+1);
        }
        
        return intervals;
    }
};