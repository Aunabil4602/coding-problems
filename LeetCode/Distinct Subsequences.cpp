/// dp O(s.length*t.length)
/// dp[i][j] stores result for ith index in s & jth index in t  
/// if s[i] matches t[j] then we can check for s[i-1] & t[j-1]
/// therefore if(s[i]==t[j])dp[i][j]+=dp[i-1][j-1]
/// also we can skip the current ith character and compare with (i-1) of s with jth of t
/// therefore dp[i][j]+=dp[i-1][j]

class Solution {
public:
    int numDistinct(string s, string t) {
        int n=s.length();
        int m=t.length();
        long long dp[n+1][m+1];
        memset(dp,0,sizeof dp);
        for(int i=0;i<=n;i++)dp[i][0]=1;
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                dp[i][j]+=dp[i-1][j];
                if(s[i-1]==t[j-1])dp[i][j]+=dp[i-1][j-1]; /// 0 indexing for string
            }
        }
        return (int)dp[n][m];
    }
};
