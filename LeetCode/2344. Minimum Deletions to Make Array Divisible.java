class Solution {
    public int minOperations(int[] nums, int[] numsDivide) {
        int gcdArray = numsDivide[0];
        for(int i=1;i<numsDivide.length;i++){
            gcdArray = getGcd(gcdArray, numsDivide[i]);
        }

        int min = Integer.MAX_VALUE;
        for(int i=0;i<nums.length;i++){
            if (gcdArray%nums[i]==0 && nums[i]<min) {
                min = nums[i];
            }
        }

        if (min == Integer.MAX_VALUE) {
            return -1;
        }

        int removalCount = 0;
        for(int i=0;i<nums.length;i++){
            if (nums[i]<min) {
                removalCount++;
            }
        }

        return removalCount;
    }

    private int getGcd(int a, int b){
        return b==0 ? a : getGcd(b, a%b);
    }
}
