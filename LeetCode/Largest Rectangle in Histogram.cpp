class Solution { ////////////////// O(2n)=O(n)
public:
    int largestRectangleArea(vector<int>& heights) {
        stack<int> dp;
        int n=heights.size();
        int ans=0;
        for(int i=0;i<n;i++){
           if(dp.empty())dp.push(i);
            else{
                while(!dp.empty() && heights[dp.top()]>=heights[i]){
                    int cur=dp.top();
                    dp.pop();
                    int area;
                    if(dp.size()>0)area=heights[cur]*(i-dp.top()-1);
                    else area=heights[cur]*(i);
                    ans=max(ans,area);
                }
                dp.push(i);
            }
            
        }
        while(!dp.empty()){
            int cur=dp.top();
            dp.pop();
            int area;
            if(dp.size()>0)area=heights[cur]*(n-dp.top()-1);
            else area=heights[cur]*(n);
            ans=max(ans,area);
        }
        return ans;
    }
};
