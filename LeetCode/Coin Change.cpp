////////////////////////////// time complexity O(amount*number of coins)
class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        int dp[amount+1];
        for(int i=0;i<=amount;i++)dp[i]=amount+5;
        dp[0]=0;
        for(auto x:coins){
            for(int i=1;i<=amount;i++){
                if(i-x>=0){
                    dp[i]=min(dp[i],1+dp[i-x]);
                }
            }
        }
        int ans=-1;
        if(dp[amount]!=amount+5)ans=dp[amount];
        return ans;
    }
};
