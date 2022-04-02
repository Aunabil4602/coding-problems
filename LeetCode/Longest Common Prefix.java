class Solution {
    public String longestCommonPrefix(String[] strs) {
        if(strs.length == 0) {
            return "";
        } else if (strs.length == 1){
            return strs[0];
        }
        
        int ans = strs[0].length();
        for(int i=1;i<strs.length;i++){
            int pos = 0;
            while(pos<ans && pos<strs[0].length() && pos<strs[i].length() && strs[0].charAt(pos)==strs[i].charAt(pos)){
                pos++;
            }
            
            ans = Math.min(pos, ans);
        }
        
        return strs[0].substring(0, ans);
    }
    

}
