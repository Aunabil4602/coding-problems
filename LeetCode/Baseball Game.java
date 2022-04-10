class Solution {
    public int calPoints(String[] ops) {
        Stack<Integer> stack = new Stack<>();
        
        for(int i=0;i<ops.length;i++){
            String op = ops[i];
            if(op.equals("C")){
                stack.pop();
            } else if(op.equals("D")) {
                stack.push(stack.peek()*2);
            } else if(op.equals("+")) {
                Integer x = stack.peek();
                stack.pop();
                
                Integer y = x + stack.peek();
                stack.push(x);
                stack.push(y);
            } else {
                stack.push(Integer.valueOf(op));
            }
        }
        
        int ans = 0;
        while(!stack.isEmpty()) {
            ans+=stack.peek();
            stack.pop();
        }
        
        return ans;
    }
}
