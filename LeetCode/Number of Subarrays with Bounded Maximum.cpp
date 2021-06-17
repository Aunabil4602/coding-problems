class Solution {
public:
    int numSubarrayBoundedMax(vector<int>& nums, int left, int right) {
        int lastNo = -1, lastYes = -1, answer = 0;
        
        for(int i=0;i<nums.size();i++){
            if(nums[i]>right)lastNo=i;
            else if(left<=nums[i] && nums[i]<=right){
                lastYes = i;
            }
            
            answer+=max(0,lastYes-lastNo);
        }
        
        return answer;
    }
};
