class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        vector<int> dp(nums.size());
        for(int i=nums.size()-1;i>=0;i--){
            dp[i]=nums[i];
            if((i+1)<nums.size())dp[i]*=dp[i+1];
        }
        int val=1;
        for(int i=0;i<nums.size();i++){
            dp[i]=val;
            if(i+1<nums.size())dp[i]*=dp[i+1];
            val*=nums[i];
        }
        return dp;
    }
};
