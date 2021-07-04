class Solution {
public:
    long long dp[20004][5];
    long long MOD;
    
    Solution(){
        MOD = 1000000007;
        memset(dp,0,sizeof dp);
        for(int i=0;i<5;i++)dp[1][i]=1;
        
        vector<int> parent[5];
        parent[0] = {1,2,4};
        parent[1] = {0,2};
        parent[2] = {1,3};
        parent[3] = {2};
        parent[4] = {2,3};
        
        for(int i=2;i<=20000;i++){
            for(int j=0;j<5;j++){
                for(auto &x: parent[j]){
                    dp[i][j] += dp[i-1][x];
                    dp[i][j]%=MOD;
                }
            }
        }
        
    }

    int countVowelPermutation(int n) {
        return (dp[n][0]+dp[n][1]+dp[n][2]+dp[n][3]+dp[n][4])%MOD;
    }
};
