class Solution {   ///////////////// manachar's algorithm O(n)
public:
    int countSubstrings(string s) {
        int n=s.length();
        if(!n)return 0;
        vector<int> dp(2*n+1,1);
        string ss;
        for(int i=0;i<n;i++){
            ss+='#';
            ss+=s[i];
        }
        ss+='#';
        for(int i=0;i<2*n+1;i++){
            int l=i-dp[i]/2-1;
            int r=i+dp[i]/2+1;
            while(l>=0 && r<(2*n+1) && (ss[l]==ss[r])){
                dp[i]+=2;
                l--;r++;
            }
            for(int j=1;j<=(dp[i]/2);j++){
                dp[i+j]=max(dp[i+j],min(dp[i-j],(dp[i]/2 - j)*2+1));
            }
        }
        int ans=0;
        for(int i=1;i<2*n;i++){
            ans+=(((dp[i]-1)/2)+1)/2;
        }
        return ans;
    }
};


class Solution { /////////////////// dp O(n^2)
public:
    int countSubstrings(string s) {
        int n=s.length();
        if(n==0)return 0;
        int dp[n+1][n+1];
        int ans=0;
        memset(dp,0,sizeof (dp));
        
        for(int len=1;len<=n;len++){
            for(int i=0;i<n;i++){
                int j=i+len-1;
                if(j>=n)continue;
                if(j-i <=1 && s[i]==s[j])dp[i][j]=1;
                else if(j-i>1 && s[i]==s[j])dp[i][j]=dp[i+1][j-1];
                ans+=dp[i][j];
            }
        }
        return ans;
    }
};
