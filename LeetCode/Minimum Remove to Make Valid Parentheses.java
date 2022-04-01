class Solution {
    public String minRemoveToMakeValid(String s) {
        Stack<Integer> stk = new Stack();
        List<Integer> toRemove = new ArrayList();
        
        for(int i = 0;i<s.length();i++) {
            toRemove.add(0);
            char c = s.charAt(i);
            if(c=='(') {
                stk.push(i);
            } else if (c==')') {
                if(stk.empty()) {
                    toRemove.set(i,1);
                } else {
                    stk.pop();
                }
            }
        }
        
        while(!stk.empty()){
            toRemove.set(stk.peek(),1);
            stk.pop();
        }
        
        StringBuilder answer = new StringBuilder();
        for(int i = 0;i<s.length();i++) {
            if (toRemove.get(i)==0) {
                answer.append(s.charAt(i));
            }
        }
        
        return answer.toString();
    }
}
