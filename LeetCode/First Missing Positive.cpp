class Solution { //O(n) and O(n)
public:
    int firstMissingPositive(vector<int>& nums) {
        unordered_map<int,int> dp;    
        for(auto x: nums)dp[x]=1;
        int ans=1;
        while(dp[ans]==1)ans++;
        return ans;
    }
};
