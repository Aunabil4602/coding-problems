////////////////////////////// solution for :II

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

//////////////////////////// solution for :I
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
