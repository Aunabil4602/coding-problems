class Solution {
    private int[][] discoveryTime;
    private int[][] lowerTime;
    private boolean[][] isArticulationPoint;
    private int time;
    private int[] neighborsX = {-1, 0, 1, 0};
    private int[] neighborsY = {0, 1, 0, -1};
    private int landsCount;

    public int minDays(int[][] grid) {
        int n = grid.length;
        int m = grid[0].length;

        discoveryTime = new int[n][m];
        lowerTime = new int[n][m];
        isArticulationPoint = new boolean[n][m];
        time = 0;
        landsCount = 0;

        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                discoveryTime[i][j] = -1;
                lowerTime[i][j] = -1;
            }
        }

        int islandsCount = 0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if (discoveryTime[i][j]==-1 && grid[i][j]==1) {  
                    islandsCount++;

                    if (islandsCount>1) {
                        return 0;
                    }
                    
                    isArticulationPoint[i][j] = dfs(i, j, -1, -1, grid) > 1;
                }
            }
        }

        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if (isArticulationPoint[i][j]) return 1;
            }
        }

        return landsCount >=2 ? 2: landsCount;
    }

    private int dfs(int x, int y, int px, int py, int[][] grid) {
        discoveryTime[x][y] = lowerTime[x][y] = time++;
        landsCount++;
        int childrenCount = 0;

        for (int i=0;i<4;i++) {
            int nx = x + neighborsX[i];
            int ny = y + neighborsY[i];

            if (nx<0 || nx>=grid.length)continue;
            if (ny<0 || ny>=grid[0].length)continue;

            if (discoveryTime[nx][ny]==-1 && grid[nx][ny]==1) {
                childrenCount++;
                dfs(nx, ny, x, y, grid);
                if (discoveryTime[x][y]<=lowerTime[nx][ny]) {
                    isArticulationPoint[x][y] = true;
                }

                lowerTime[x][y] = Math.min(lowerTime[nx][ny], lowerTime[x][y]);
            } else if(discoveryTime[nx][ny]!=-1 && grid[nx][ny]==1) {
                lowerTime[x][y] = Math.min(discoveryTime[nx][ny], lowerTime[x][y]);
            }
        }

        return childrenCount;
    }
}
