///////////////////////// This is O(s*p) solution... there is also (s+p) solution using two pointers. 

class Solution {
public:
    bool isMatch(string s, string p) {
        int len1=s.length();
        int len2=p.length();
        int dp[len1+1][len2+1];
        memset(dp,0,sizeof(dp));
        dp[0][0]=1;
        for(int i=0;i<len2 && p[i]=='*';i++)dp[0][i+1]=1;
    
        for(int i=1;i<=len1;i++){
            for(int j=1;j<=len2;j++){
                if(p[j-1]=='*'){
                    dp[i][j]=max({dp[i-1][j],dp[i-1][j-1],dp[i][j-1]});
                }
                else{
                    dp[i][j]=dp[i-1][j-1];
                    if(p[j-1]!='?')dp[i][j]=min((int)(s[i-1]==p[j-1]),dp[i][j]);
                }
            }
        }
        return dp[len1][len2];
    }
};
