class Solution {
public:
    string longestPrefix(string s) {
        int n=s.length();
        int dp[n+1];
        memset(dp,-1,sizeof dp);
        int j=0;
        int i=1;
        while(i<n){
            if(s[i]==s[j]){
                dp[i]=j;
                j++;
                i++;
            }
            else {
                if(j!=0)j=dp[j-1]+1;
                else i++;
            }
        }
        int len=dp[n-1]+1;
        return s.substr(0,len);
    }
};
