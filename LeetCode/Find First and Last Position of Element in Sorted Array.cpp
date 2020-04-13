class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        vector<int> pos(2);
        pos[0]=lower_bound(nums.begin(),nums.end(),target)-nums.begin();
        pos[1]=upper_bound(nums.begin(),nums.end(),target)-nums.begin();
        pos[1]--;
        if(pos[0]>pos[1])pos[0]=pos[1]=-1;
        return pos;
    }
};
