class Solution {
public:
    bool canJump(vector<int>& nums) {
        int mx=0;
        for(int i=0;i<nums.size();i++){
            if(i>mx)break;
            mx=max(i+nums[i],mx);
        }
        return (nums.size()-1)<=(mx);
    }
};
