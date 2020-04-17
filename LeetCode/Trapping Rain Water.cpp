class Solution {
public:
    int trap(vector<int>& height) {
        int n=height.size();
        if(n==0)return 0;
        int dp[n][2];
        memset(dp,0,sizeof(dp));
        dp[0][0]=height[0];
        for(int i=1;i<n;i++){
            dp[i][0]=max(height[i],dp[i-1][0]);
        }
        dp[n-1][1]=height[n-1];
        for(int i=n-2;i>=0;i--){
            dp[i][1]=max(height[i],dp[i+1][1]);
        }
        int ans=0;
        for(int i=0;i<n;i++){
            int l=height[i],r=height[i];
            if(i>0)l=max(l,dp[i-1][0]);
            if(i+1<n)r=max(r,dp[i+1][1]);
            ans+=(min(l,r)-height[i]);
        }
        return ans;
    }
};
