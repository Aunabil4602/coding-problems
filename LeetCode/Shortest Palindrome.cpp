class Solution { ////////////////// KMP O(n)
public:
    string shortestPalindrome(string s) {
        int n=s.length();
        if(n==0)return "";
        string rev=s;
        reverse(rev.begin(),rev.end());
        int dp[n];
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
        i=0,j=0;
        int ans=0;
        while(i<n){
            if(rev[i]==s[j]){
                i++;
                j++;
                ans=j;
            }
            else {
                if(j!=0)j=dp[j-1]+1;
                else i++;
            }
        }
        string hehe;
        for(int i=n-1;i>=ans;i--)hehe+=s[i];
        hehe+=s;
        return hehe;
    }
};
