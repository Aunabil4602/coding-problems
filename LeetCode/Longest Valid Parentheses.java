class Solution {
    public int longestValidParentheses(String s) {
        Stack<Integer> stack = new Stack();
        int[] arr = new int[s.length()];
        
        for(int i=0;i<s.length();i++) {
            if(s.charAt(i)=='(') {
                stack.push(i);
            } else if (s.charAt(i)==')') {
                if(!stack.empty()) {
                    arr[i] = i - stack.peek() + 1;
                    stack.pop();
                }
            }
        }
        
        int max= 0;
        int len = 0;
        int last = s.length() -1;
        while(last>0) {
            if(arr[last]>0) {
                len+=arr[last];
                last-=arr[last];
            } else {
                len = 0;
                last--;
            }
            max = Math.max(max, len);
        }
        
        return max;
    }
}
