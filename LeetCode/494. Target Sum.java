class Solution {
    public int findTargetSumWays(int[] nums, int target) {
        int MAX_SUM = 20*1000;
        int[][] dp = new int[MAX_SUM+1][21];

        target+=1000;
        dp[1000][0] = 1;
        
        for(int j=1;j<=nums.length;j++){
            for(int i=0;i<=MAX_SUM;i++){
                dp[i][j] += (i-nums[j-1]>=0)?dp[i-nums[j-1]][j-1]:0;
                dp[i][j] += (i+nums[j-1]<=MAX_SUM)?dp[i+nums[j-1]][j-1]:0;
            }
        }

        return dp[target][nums.length];
    }
}
