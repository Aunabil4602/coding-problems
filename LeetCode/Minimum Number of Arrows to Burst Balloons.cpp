bool cmp(vector<int> a,vector<int> b){
    if(a[1]<=b[1])return true;
    return false;
    
}

class Solution {
public:
    int findMinArrowShots(vector<vector<int>>& points) {
        sort(points.begin(),points.end(),cmp);
        
        
        int ans=0;
        if(points.size()==0)return ans;
        
        ans++;
        int cur=0;
        for(int i=1;i<points.size();i++){
            if(points[cur][1]>=points[i][0])continue;
            ans++;
            cur=i;
        }
        
        return ans;
        
    }
};
