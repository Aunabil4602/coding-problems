class Pair {
    public int first;
    public int second;
    Pair(int x, int y) {
        this.first = x;
        this.second = y;
    }
    
    public int getFirst() {
        return this.first;
    }
    
    public int getSecond() {
        return this.second;
    }
    
    public void setFirst(int x) {
        this.first = x;
    }
    
    public void setSecond(int y) {
        this.second = y;
    }
}


class Solution {
    int dist[];
    boolean visited[];
    List<List<Pair>> adj;
    private static final int MAX_DIST = 1000000;
    
    public int networkDelayTime(int[][] times, int n, int k) {
        adj = new ArrayList();
        for(int i=0;i<n;i++) {
            adj.add(new ArrayList()); 
        }
        
        for(int i=0;i<times.length;i++) {
            adj.get(times[i][0]-1).add(new Pair(times[i][1]-1, times[i][2]));
        }
        
        dist = new int[n];
        for(int i=0;i<n;i++) {
            dist[i] = MAX_DIST;
        }
        
        visited = new boolean[n];
        
        Set<Pair> sortedDist = new TreeSet<Pair>((p1, p2) -> {return (p1==p2)? 0: (p1.second>p2.second?1:-1);});
        sortedDist.add(new Pair(--k, 0));
        dist[k] = 0;
        
        while(!sortedDist.isEmpty()) {
            
            Pair p = sortedDist.iterator().next();
            sortedDist.remove(p);
            
            if(visited[p.first]) {
                continue;
            }
            
            visited[p.first] = true;
            
            for(Pair v: adj.get(p.first)) {
                if(!visited[v.first] && dist[v.first]>(p.second + v.second)) {
                    dist[v.first] = p.second + v.second;
                    sortedDist.add(new Pair(v.first, dist[v.first]));
                }
            }
        }
        
        int ans = -1;
        for(int i=0;i<n;i++) {
            if(dist[i]==MAX_DIST) {
                return -1;
            }
            ans = ans<dist[i]? dist[i]:ans;
        }
        
        return ans;
    }
}
