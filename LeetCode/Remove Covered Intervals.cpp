class Solution {
public:
    int removeCoveredIntervals(vector<vector<int>>& intervals) {
        int ans=0;
        for(int i=0;i<intervals.size();i++){
            bool ck=true;
            for(int j=0;j<intervals.size();j++){
                if(i==j)continue;
                if(intervals[i][0]>=intervals[j][0] && intervals[i][1]<=intervals[j][1])ck=false;
            }
            if(ck)ans++;
        }
        return ans;
        
    }
};
