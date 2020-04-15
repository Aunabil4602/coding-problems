class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        vector<int> dp;
        for(auto x:nums){
            int pos=lower_bound(dp.begin(),dp.end(),x)-dp.begin();
            if(pos<dp.size())dp[pos]=x;
            else dp.push_back(x);
        }
        return dp.size();
    }
};
