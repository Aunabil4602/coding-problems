class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        unordered_map<int,int> dp;
        int sum=0;
        long long ans=0;
        dp[sum]++;
        for(auto x:nums){
            sum+=x;
            ans+=dp[sum-k];
            dp[sum]++;
        }
        return ans;
    }
};
