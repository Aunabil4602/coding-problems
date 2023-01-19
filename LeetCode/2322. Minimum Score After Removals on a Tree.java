class Solution {
    private List<Integer>[] adjacents;
    private int[] xor;
    private int[] values;
    private int[] depth; // discovery time
    private int[] last;
    private int id;


    public int minimumScore(int[] nums, int[][] edges) {
        int n = nums.length;

        id = 0;
        values = nums;
        xor = new int[n];
        adjacents = new List[n];
        depth = new int[n];
        last = new int[n];

        for(int i=0;i<n;i++){
            adjacents[i] = new ArrayList<>();
        }

        int total = 0;
        for(int num: nums){
            total^=num;
        }    

        for(int i=1;i<n;i++){
            adjacents[edges[i-1][0]].add(edges[i-1][1]);
            adjacents[edges[i-1][1]].add(edges[i-1][0]);
        }

        dfs(0, -1);

        int min = Integer.MAX_VALUE;
        for(int i=1;i<n;i++){
            for(int j=i+1;j<n;j++){
                int c1 = getChild(edges[i-1]);
                int c2 = getChild(edges[j-1]);

                if (depth[c1]>depth[c2]){
                    int temp = c2;
                    c2 = c1;
                    c1 = temp;
                }

                if(!(depth[c1]<=depth[c2] && depth[c2]<=last[c1])){
                    int xor1 = xor[c1];
                    int xor2 = xor[c2];
                    int xor3 = total^xor1^xor2;

                    int cmax = Math.max(xor1,Math.max(xor2,xor3));
                    int cmin = Math.min(xor1, Math.min(xor2,xor3));

                    min = Math.min(min, cmax-cmin);     
                } else {
                    int xor1 = xor[c1]^xor[c2];
                    int xor2 = xor[c2];
                    int xor3 = total^xor[c1];

                    int cmax = Math.max(xor1,Math.max(xor2,xor3));
                    int cmin = Math.min(xor1, Math.min(xor2,xor3));

                    min = Math.min(min, cmax-cmin); 
                }
            }
        }

        return min;
    }

    private void dfs(int v, int p) {
        xor[v] = values[v];
        depth[v]= id++;
        last[v]=depth[v];

        for(int x: adjacents[v]){
            if (x!=p) {
                dfs(x, v);
                xor[v]^=xor[x];
                last[v]=last[x];
            }
        }     
    }

    private int getChild(int[] edge) {
        if (depth[edge[0]]>depth[edge[1]]) return edge[0];
        return edge[1];
    }
}
