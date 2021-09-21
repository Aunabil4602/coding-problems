class Solution {
    unsigned long long dp[1005][1005];
public:
    int numDistinct(string s, string t) {
        int lens=s.length();
        int lent=t.length();
        
        for(int i=0;i<=lens;i++){
            for(int j=0;j<=lent;j++){
                dp[i][j] = 0;
            }
            dp[i][0]=1;
        }
        
        for(int j=1;j<=lent;j++){
            for(int i=1;i<=lens;i++){
                dp[i][j] = dp[i-1][j];
                
                if(s[i-1]==t[j-1]){
                    dp[i][j] += dp[i-1][j-1];
                }
                
            }
        }
        
        return dp[lens][lent];
    }
};
