class Solution {
    public void nextPermutation(int[] nums) {
        int n = nums.length;
        if(n==0){
            return;
        }
        
        int last = n - 1;
        while(last>0 && nums[last-1]>=nums[last]) {
            last--;
        }
        
        int l = last, r = n -1;
        int temp = 0;
        while(l<r) {
            temp = nums[l];
            nums[l] = nums[r];
            nums[r] = temp;
            l++;
            r--;
        }
        
        if(last>0) {
            for(int i=last;i<n;i++){
                if(nums[last-1]<nums[i]){
                    temp = nums[last-1];
                    nums[last-1]=nums[i];
                    nums[i]=temp;
                    break;
                }
            }
        }
    }
}
