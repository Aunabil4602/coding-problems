class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int n=grid.size();
        if(n==0)return 0;
        int m=grid[0].size();
        int dp[n+1][m+1];
        memset(dp,0,sizeof(dp));
        for(int i=n-1;i>=0;i--)for(int j=m-1;j>=0;j--){
            int sum=1e9;
            if(i==n-1 && j==m-1)sum=0;
            if(j+1<m)sum=min(sum,dp[i][j+1]);
            if(i+1<n)sum=min(sum,dp[i+1][j]);
            dp[i][j]=grid[i][j]+sum;
        }
        return dp[0][0];
    }
};
