class Solution {
    private List<List<Integer>> ans;
    public List<List<Integer>> combinationSum3(int k, int n) {
        this.ans = new ArrayList();
        find(new ArrayList(), 0 ,0, k, n);
        
        return ans;
    }
    
    private void find(List<Integer> list, int sum, int max, int k, int n) {
        if(list.size()==k){
            if(sum==n){
                // System.out.println(list);
                this.ans.add(new ArrayList(list));
            }
            
            return;
        }
        
        for(int i= max+1; i<10;i++){
            if(sum+i<=n) {
                list.add(i);
                find(list, sum+i, i, k, n);
                list.remove(list.size() -1);
            }
        }
    }
}
