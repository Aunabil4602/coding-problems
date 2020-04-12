//////////// solution 1: DP ,complexity O(n^2) 
//////////// There is also O(n) solution using  Manacher's Algorithm.
#define N 1005

int dp[N][N];

class Solution {
public:
    string longestPalindrome(string s) {
        memset(dp,0,sizeof(dp));
        for(int i=0;i<N;i++)dp[i][i]=1;
        int mx=1;
        string ans;
        ans+=s[0];
        for(int len=1;len<s.length();len++){
            for(int i=0;i+len<s.length();i++){
                if(s[i]==s[i+len]){
                    if(i+1 <= i+len-1)dp[i][i+len]=dp[i+1][i+len-1];
                    else dp[i][i+len]=1;
                }
                if(dp[i][i+len] && len+1>mx)mx=len+1,ans=s.substr(i,mx);
            }
        }
        return ans;
    }
};
