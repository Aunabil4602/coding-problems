class Solution {
public:
    int maxProduct(vector<int>& nums) {
        if(nums.size()==0)return 0;
        long long pos=nums[0],neg=nums[0],mx=nums[0],mn=nums[0];
        long long ans=nums[0];
        for(int i=1;i<nums.size();i++){
            pos=nums[i]*mx;
            neg=nums[i]*mn;
            mx=max<long long>({pos,neg,nums[i]});
            mn=min<long long>({pos,neg,nums[i]});
            ans=max<long long>(ans,mx);
        }
        return ans;
    }
};
