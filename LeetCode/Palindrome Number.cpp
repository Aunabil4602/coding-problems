class Solution {
    public boolean isPalindrome(int x) {
        if(x<0) {
            return false;
        }
        
        byte [] nums = new byte[11];
        int pos = 0;
        while(x>0) {
            int digit = x%10;
            nums[pos++] = (byte)digit;
            x/=10;
        }
        
        int l = 0;
        pos--;
        while(l<pos) {
            if(nums[l]!=nums[pos]) {
                return false;
            }
            l++;
            pos--;
        }
        
        return true;
    }
}
