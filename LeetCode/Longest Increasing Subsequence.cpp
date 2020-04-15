class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        if(nums.size()==0)return 0;
        vector<int> dp;
        dp.push_back(nums[0]);
        for(auto x:nums){
            int pos=lower_bound(dp.begin(),dp.end(),x)-dp.begin();
            if(pos<dp.size())dp[pos]=x;
            else dp.push_back(x);
        }
        return dp.size();
    }
};
