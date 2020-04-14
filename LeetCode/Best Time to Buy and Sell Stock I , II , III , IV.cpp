////////////////////////////// solution for :II , complexity O (n)

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n=prices.size();
        int ans=0;
        for(int i=1;i<n;i++){
            ans+=max(0,(prices[i]-prices[i-1]));
        }
        return ans;
    }
};

//////////////////////////// solution for :I  , complexity O (n)
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int mn=1e7;
        int mx=0;
        for(int i=0;i<prices.size();i++){
            mn=min(mn,prices[i]);
            mx=max(prices[i]-mn,mx);
        }
        return mx;
    }
};

/////////////////////////// solution for :III , complexity O (n)

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int dp[prices.size()];
        memset(dp,0,sizeof(dp));
        int mn=1e7;
        for(int i=0;i<prices.size();i++){
            mn=min(mn,prices[i]);
            dp[i]=prices[i]-mn;
            if(i>0)dp[i]=max(dp[i],dp[i-1]);
            
        }
       
        int mx=0;
        int ans=0;
        int cost=0;
        for(int i=prices.size()-1;i>=0;i--){
            mx=max(prices[i],mx);
            cost=mx-prices[i];
            if(i>0)cost+=dp[i-1];
            ans=max(ans,cost);
        }
        return ans;
    }
};

 /////////////////////////////// solution for:IV, complexity O(k*n)

class Solution {
public:
    int maxProfit(int k, vector<int>& prices) {
        int dp[prices.size()+2];
        int old[prices.size()+2];
        memset(dp,0,sizeof(dp));
        memset(old,0,sizeof(old));
        int n=prices.size();
        k=min(k,n/2+1);
        while(k--){
            int best=-100000;
            for(int i=1;i<=n;i++){
                dp[i]=max(dp[i],dp[i-1]);
                dp[i]=max(dp[i],prices[i-1]+best);
                best=max(best,old[i-1]-prices[i-1]);
            }
            for(int i=1;i<=n;i++)old[i]=dp[i];
        }
        return dp[n];
    }
};
