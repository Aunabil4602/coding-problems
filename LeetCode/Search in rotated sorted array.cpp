class Solution {
public:
    int search(vector<int>& nums, int target) {
        if(nums.size()==0)return -1;
        int l=0,r=nums.size()-1;
        int mid;
        while(l<=r){
            mid=l+(r-l)/2;
            if(l==r)break;
            else if(nums[mid]>nums.back())l=mid+1;
            else r=mid;
        }
        int start=mid;
        int pos=lower_bound(nums.begin(),nums.begin()+start,target)-nums.begin();
        if(pos<start && nums[pos]==target)return pos;
        if(pos>=nums.size())return -1;
        pos=lower_bound(nums.begin()+start,nums.end(),target)-nums.begin();
        if(pos<nums.size() && nums[pos]==target)return pos;
        return -1;
    }
};
