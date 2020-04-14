/////////////////////////////////////// Kadane's algorithm O(n)

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int sum=nums[0];
        int mx=nums[0];
        for(int i=1;i<nums.size();i++){
            sum=max(nums[i],sum+nums[i]);
            mx=max(mx,sum);
        }
        return mx;
    }
};

///////////////////////////////// Divide & Conquer O(nlogn)
int DC(int left,int right, vector<int>& nums)
{
    if(left>right)return 0;
    if(left==right)return nums[left];
    int mid=left+(right-left)/2;
    int lsum=DC(left,mid,nums);
    int rsum=DC(mid+1,right,nums);
    
    int mx=nums[mid],sum=nums[mid];
    for(int i=mid-1;i>=left;i--){
        sum+=nums[i];
        mx=max(mx,sum);
    }
    sum=nums[mid+1];
    int mx1=nums[mid+1];
    for(int i=mid+2;i<=right;i++){
        sum+=nums[i];
        mx1=max(sum,mx1);
    }
    
    return max({mx+mx1,lsum,rsum});
}

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int n=nums.size();
        
        return DC(0,n-1,nums);
    }
};
