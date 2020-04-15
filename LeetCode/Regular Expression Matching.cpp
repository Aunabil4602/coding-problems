class Solution {
public:
    bool isMatch(string s, string p) {
        int len1=s.length();
        int len2=p.length();
        int dp[len1+1][len2+1];
        memset(dp,0,sizeof(dp));
        dp[0][0]=1;
        for(int i=1;i<len2 && p[i]=='*';i+=2)dp[0][i+1]=1;
    
        for(int i=1;i<=len1;i++){
            for(int j=1;j<=len2;j++){
                if(p[j-1]=='*'){
                    char c=p[j-2];
                    dp[i][j]=max({dp[i][j-2],(c==s[i-1] || c=='.')*dp[i-1][j-2],(c==s[i-1] || c=='.')*dp[i-1][j]});   
                }
                else{
                    dp[i][j]=min((int)(s[i-1]==p[j-1] || p[j-1]=='.'),dp[i-1][j-1]);
                }
            }
        }
        return dp[len1][len2];
    }
};
