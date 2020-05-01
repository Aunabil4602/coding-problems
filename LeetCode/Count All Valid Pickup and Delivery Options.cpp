/////////////// There is O(n) solution using conbinations = (2*n)C2 x (2*n-2)C2 x (2*n-4)C2 ........ = (n!)/ 2^(n-1)

class Solution {  ////////// this is O(n^2) solution using dp
 public:
    int countOrders(int n) {
        n<<=1;
        long long dp[n+1][n+1];
        memset(dp,0,sizeof dp);
        long long mod=1e9+7;
        
        dp[0][0]=1;
        for(int i=1;i<=n;i++){
            
            for(int j=1+i/2;j<=min(i,n/2);j++){
                dp[i][j]+=(dp[i-1][j-1]*(n/2-(j-1)))%mod;
                dp[i][j]%=mod;
            }
            int mx=min(n/2,i-1);
            int mn=1+(i-1)/2;
            for(int j=mn;j<=mx;j++){
                int rem=(j)-(i-1-j);
                dp[i][j]+=(dp[i-1][j]*(rem))%mod;
                dp[i][j]%=mod;
            }
        }
     
        return dp[n][n/2];
    }
};
