/////////////////////// n=S.legnth() , completxity max( O(n^2) , O(n*26) ) 
/////////////////////// better explanation https://zxi.mytechroad.com/blog/dynamic-programming/leetcode-730-count-different-palindromic-subsequences/
////////////////////// used another dp to find out the leftmost and rightmost positions of a character...
//////////////////////                    ...in a range in O(1), it took (n*26) to build the dp.

#define LL long long
class Solution {
public:
    int countPalindromicSubsequences(string S) {
        LL mod=1e9+7;
        int n=S.length();
        string s=S;
        LL dp[n+1][n+2];
        int posL[26][n+2];
        memset(posL,-1,sizeof posL);
        for(int i=1;i<=n;i++){
            for(int c=0;c<26;c++){
                posL[c][i]=posL[c][i-1];
                if(c==(s[i-1]-'a')){
                    posL[c][i]=i;
                }
            }
        }
        int posR[26][n+2];
        for(int i=0;i<=n+1;i++)for(int c=0;c<26;c++)posR[c][i]=n+1;
        for(int i=n;i>=1;i--){
            for(int c=0;c<26;c++){
                posR[c][i]=posR[c][i+1];
                if(c==(s[i-1]-'a')){
                    posR[c][i]=i;
                }
            }
        }
        for(int i=0;i<26;i++){
            posL[i][n+1]=posL[i][n];
            posR[i][0]=posR[i][1];
        }
        
        memset(dp,0,sizeof dp);
        for(int i=1;i<=n;i++)dp[i][i]=1;
        for(int len=2;len<=n;len++){
            for(int i=1;i+len-1<=n;i++){
                int j=i+len-1;
                if(s[i-1]==s[j-1]){
                    int cnt=0;
                    int fst=-1;
                    int et=-1;
                    int c=s[i-1]-'a';
                    if(posL[c][j-1]>i && posR[c][i+1]<j){
                        fst=posR[c][i+1];
                        et=posL[c][j-1];
                        cnt=1;
                        if(fst!=et)cnt=2;
                    }
                    dp[i][j]=2*dp[i+1][j-1];
                    if(!cnt)dp[i][j]+=2;
                    else if(cnt==1){
                        dp[i][j]++;
                    }
                    else{
                       dp[i][j]=dp[i][j]+mod-dp[fst+1][et-1];
                    }
                }
                else dp[i][j]=dp[i][j-1]+dp[i+1][j]-dp[i+1][j-1]+mod;
                dp[i][j]%=mod;
            }   
        }
        return (int)dp[1][n];
    }
};
