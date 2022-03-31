class Solution {
public:
    int splitArray(vector<int>& nums, int m) {
        int n = nums.size();
        
        int dp[n][m];
        
        int sum = 0;
        for(int i=0;i<n;i++){
            sum+=nums[i];
            dp[i][0] = sum;
        }
        
        for(int i=0;i<n;i++) {
            for(int k=1;k<m;k++) {
                dp[i][k] = 100000000;
                int sum = 0;
                for(int j=i;j>0;j--){
                    sum+=nums[j];
                    dp[i][k] = min(max(dp[j-1][k-1],sum),dp[i][k]);
                }
            }
        }
        
        return dp[n-1][m-1];
    }
};
