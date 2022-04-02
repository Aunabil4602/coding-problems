class Solution {
    public boolean validPalindrome(String s) {
        int l = 0;
        int r = s.length() -1;
        
        return validPalindrome(s, l, r, true);
    }
    
    public boolean validPalindrome(String s, int l, int r, boolean req) {
        while(l<r) {
            if(s.charAt(l)==s.charAt(r)){
                l++;
                r--;
            } else {
                if(req) {
                    return validPalindrome(s, l+1, r, false) || validPalindrome(s, l, r-1, false); 
                }
                return false;
            }
        }
        
        return true;
    }
}
