class Solution {
    public int countSubstrings(String s) {
        int n = s.length();
        int[][] dp = new int[n][n];
        
        int cnt = 0;
        for(int i=0;i<n;i++) {
            dp[i][i] = 1;
            cnt++;
        }
        
        
        for(int len = 2;len<=n;len++) {
            for(int i=0;i<n;i++) {
                int last = i+len-1;
                if((last)>=n) {
                    break;
                }
                
                if(s.charAt(i)==s.charAt(last) && ((i+1)>=(last-1) || dp[i+1][last-1]==1)) {
                    dp[i][last] = 1;
                    cnt++;
                }
            }
        }
        
        return cnt;
    }
}
