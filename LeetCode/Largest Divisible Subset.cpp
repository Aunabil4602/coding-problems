class Solution { // O(n^2)
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        int n=nums.size();
        if(!n)return vector<int> ();
        
        sort(nums.begin(),nums.end());
        int dp[n+1];
        int p[n+1];
        memset(dp,1,sizeof dp);
        memset(p,-1,sizeof p);
        
        
        int mx=1;
        int pos=0;
        for(int i=1;i<n;i++){
            for(int j=i-1;j>=0;j--){
                if(nums[i]%nums[j]==0 && dp[i]<(1+dp[j])){
                    dp[i]=1+dp[j];
                    p[i]=j;
                }
            }
            if(mx<dp[i]){
                mx=dp[i];
                pos=i;
            }
        }
        
        
        vector<int> ans;
        int cur=pos;
        while(cur!=-1){
            ans.push_back(nums[cur]);
            cur=p[cur];
        }
        
        return ans;
    }
};
