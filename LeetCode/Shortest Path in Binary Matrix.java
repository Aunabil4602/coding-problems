class Pair {
    public int f,s;
    Pair(int x, int y) {
        this.f = x;
        this.s = y;
    }
}

class Solution {
    private static final int[] X = {-1, 0, 1, -1, 1, -1, 0, 1};
    private static final int[] Y = {-1, -1, -1, 0, 0, 1, 1, 1};
    
    public int shortestPathBinaryMatrix(int[][] grid) {
        int n = grid.length;
        int m = grid[0].length;
        
        if(grid[0][0]==1 ||  grid[n-1][m-1]==1) {
            return -1;
        }
        
        int[][] dis = new int[n][m];
        int[][] visited = new int[n][m];
        Queue<Pair> q = new LinkedList();
        
        q.add(new Pair(0,0));
        visited[0][0] = 1;
        
        while(!q.isEmpty()) {
            Pair p = q.peek();
            q.remove();
            
            for(int i=0;i<8;i++) {
                int nx = p.f + X[i];
                int ny = p.s + Y[i];
                
                if(nx<0 || nx>=n || ny<0 || ny>=m) {
                    continue;
                }
                
                if(grid[nx][ny]==1 || visited[nx][ny]==1) {
                    continue;
                }
                
                visited[nx][ny] = 1;
                dis[nx][ny] = dis[p.f][p.s] + 1;
                q.add(new Pair(nx, ny));
            }
        }
        
        return visited[n-1][m-1]==0?-1:dis[n-1][m-1]+1;
    }
}
