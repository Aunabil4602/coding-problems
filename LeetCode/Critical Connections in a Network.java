class Solution {
    private int time = 1;
    private List<Integer>[] adj;
    private int[] dis;
    private int[] low;
    private List<List<Integer>> bridges;
    
    
    public List<List<Integer>> criticalConnections(int n, List<List<Integer>> connections) {
        this.time = 1;
        this.adj = new List[n];
        for (int i=0;i<n;i++) {
            this.adj[i] = new ArrayList();
        }
        this.dis = new int[n];
        this.low = new int[n];
        this.bridges = new ArrayList<List<Integer>>();
        
        
        for (List<Integer> p: connections) {
            this.adj[p.get(0)].add(p.get(1));
            this.adj[p.get(1)].add(p.get(0));
        }
        
        findBridges(0, -1);
    
        return bridges;
    }
    
    private void findBridges(int u, int p) {
        dis[u] = low[u] = time++;
        
        for (Integer V: this.adj[u]) {
            int v = V.intValue();
            
            if (v==p) {
                continue;    
            }
            
            if (this.dis[v]==0) {
                
                findBridges(v, u);
                
                if (dis[u]<low[v]) {
                    List list = new ArrayList<Integer>();
                    list.add(u);
                    list.add(v);
                    
                    bridges.add(list);
                }
                
                low[u] = low[u]<low[v] ? low[u] : low[v];
            } else {
                low[u] = low[u]<dis[v] ? low[u] : dis[v];
            }
        }
    }
}
