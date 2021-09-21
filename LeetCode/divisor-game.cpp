class Solution {
    int dp[1005];
public:
    bool divisorGame(int n) {
        memset(dp,0,sizeof dp);
        for(int i=1;i<=n;i++){
            for(int j=1;j<i;j++){
                if(i%j==0){
                    if(dp[i]==dp[i-j])dp[i]=1;
                }
            }
        }
        
        return dp[n];
    }
};
