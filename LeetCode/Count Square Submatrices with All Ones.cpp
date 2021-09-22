class Solution {
public:
    int countSquares(vector<vector<int>>& matrix) {
        int n = matrix.size();
        
        int m =0;
        if(n>0){
            m = matrix[0].size();
        }
        
        int dp[n+1][m+1];
        memset(dp,0,sizeof dp);
        int ans=0; 
        
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(matrix[i][j]){
                    if(i==0 || j==0) dp[i][j]=1;
                    else dp[i][j] = 1 + min({dp[i-1][j],dp[i][j-1],dp[i-1][j-1]});            
                }
                
                ans+=dp[i][j];
            }
        }
        
        
        return ans;
    }
};
