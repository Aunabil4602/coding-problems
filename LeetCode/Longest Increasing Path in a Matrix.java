class Pair {
    public int x, y;
    Pair(int X, int Y) {
        this.x = X;
        this.y = Y;
    }
}

class Solution {
    
    private int[][] dis;
    private Set<Pair> sorted;
    private int[] X = {-1, 0, 0, 1};
    private int[] Y = {0, -1, 1, 0};
    
    public int longestIncreasingPath(int[][] matrix) {
        int n = matrix.length;
        int m = matrix[0].length;
        
        dis = new int[n][m];
        
        sorted = new TreeSet<Pair>((p1, p2) -> {
            
            
            int dif = dis[p2.x][p2.y] - dis[p1.x][p1.y];
            if (dif>0) {
                return 1;
            } else if (dif<0) {
                return -1;
            } else {
                if(p1==p2 || (p1.x==p2.x && p1.y==p2.y)) {
                    return 0;
                }
                
                return (p2.x*m+p2.y) - (p1.x*m+p1.y);
            }
        });
        
        int cnt = 0;
        for (int i=0;i<n;i++) {
            for (int j=0;j<m;j++) {
                sorted.add(new Pair(i, j));
            }
        }
        
        
        while(!sorted.isEmpty()) {
            Pair p = sorted.iterator().next();
            
            for(int i=0;i<4;i++) {
                int nx = p.x + X[i];
                int ny = p.y + Y[i];
                
                if(nx<0 || nx>=n || ny<0 || ny>=m) {
                    continue;
                }
                
                if (matrix[p.x][p.y]>matrix[nx][ny] && (dis[p.x][p.y]+1 > dis[nx][ny])) {
                    
                    
                    
                    Pair np = new Pair(nx, ny);
                    sorted.remove(np);
                    
                    dis[nx][ny] = dis[p.x][p.y] +1;
                    sorted.add(np);
                }
            }
        }
        
        int ans = -1;
        for (int i=0;i<n;i++) {
            for (int j=0;j<m;j++) {
                if(ans<dis[i][j]) {
                    ans = dis[i][j];
                }
            }
        }
        
        return ans+1;
    }
}
