class Solution {
public:
    int countVowelStrings(int n) {
        long long dp[5] = {1,1,1,1,1};
        long long dp2[5] = {0,0,0,0,0};
        for(int i=1;i<n;i++){
            for(int j=4;j>=0;j--){
                for(int k=0;k<=j;k++)
                    dp2[j]+=dp[k];
            }
            
            for(int i=0;i<5;i++)dp[i]=dp2[i],dp2[i]=0;
        }
        
        return (dp[0]+dp[1]+dp[2]+dp[3]+dp[4]);
    }
};
