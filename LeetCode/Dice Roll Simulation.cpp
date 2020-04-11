
class Solution {
public:
    int dieSimulator(int n, vector<int>& rollMax) {
        int dp[n+2][10];
        memset(dp,0,sizeof (dp));
        long long mod=1e9+7;
        dp[0][0]=1;
        for(int i=1;i<=n;i++){
            for(int j=1;j<=6;j++){
                for(int k=1;k<=rollMax[j-1] && k<=i;k++){
                    for(int pre=0;pre<=6;pre++){
                        if(j==pre)continue;
                        dp[i][j]+=dp[i-k][pre];
                        dp[i][j]%=mod;
                    }
                }
            }
        }
        long long sum=0;
        for(int i=1;i<=6;i++){
            sum+=dp[n][i];
            sum%=mod;
        }

        return sum;
    }
};
