class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        map<int,int> dp;
        for(int i=0;i<nums.size();i++){
            if(nums[i]==0)nums[i]=-1;
        }
        
        int ans=0,sum=0;
        dp[0]=-1;
        for(int i=0;i<nums.size();i++){
            sum+=nums[i];
            if(dp.find(sum)!=dp.end())ans=max(i-dp[sum],ans);
            else dp[sum]=i;
        }
        
        return ans;
        
    }
};
