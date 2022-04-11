class Solution {
    public List<List<Integer>> shiftGrid(int[][] grid, int k) {
        int n = grid.length;
        int m = grid[0].length;
        
        List<Integer> arr = new ArrayList();
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                arr.add(grid[i][j]);
            }
        }
        
        
        List<List<Integer>> ans = new ArrayList();
        List<Integer> curList = new ArrayList();
        int pos = n*m - k%(n*m);
        for(int i=0;i<n*m;i++){
            pos%=n*m;
            if(i>0 && i%m==0){
                ans.add(curList);
                curList = new ArrayList();
            }
            
            curList.add(arr.get(pos));
            pos++;
        }
        ans.add(curList);
        
        return ans;
    }
}
