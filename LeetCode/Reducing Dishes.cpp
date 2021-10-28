class Solution {
public:
    int maxSatisfaction(vector<int>& satisfaction) {
        int n = satisfaction.size();
        if(n==0)return 0;

        sort(satisfaction.begin(),satisfaction.end());
        reverse(satisfaction.begin(),satisfaction.end());
        
        
        vector<int> dp(n,0);
        dp[0] = satisfaction[0];
        for(int i=1;i<n;i++){
            dp[i]=satisfaction[i]+dp[i-1];
        }
        
        int cur = 0;
        int mx = 0;
        for(int i=0;i<n;i++){
            cur+=dp[i];
            mx = max(mx,cur);
        }
        
        return mx;
    }
};
