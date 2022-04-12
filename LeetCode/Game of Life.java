class Solution {
    private int[] X = {-1,-1,-1,0,0,1,1,1};
    private int[] Y = {-1,0,1,-1,1,-1,0,1};
    
    public void gameOfLife(int[][] board) {
        
        int n = board.length;
        int m = board[0].length;
        
        for(int x=0;x<n;x++){
            for(int y=0;y<m;y++){
                int cnt = countNeighbor(x,y, n,m,board);
                if(board[x][y]==1){
                    if(cnt!=3 && cnt!=2)board[x][y]=4;
                    else board[x][y]=5;
                } else {
                    if(cnt==3)board[x][y]=3;
                    else board[x][y]=2;
                }
            }
        }
        
        for(int x=0;x<n;x++){
            for(int y=0;y<m;y++){
                if(board[x][y]>3){
                    board[x][y]-=4;
                } else {
                    board[x][y]-=2; 
                }
            }
        }
    }
    
    private int countNeighbor(int x, int y, int n, int m, int[][] board) {
        int sum = 0;
        for(int i=0;i<8;i++){
            int curX = x + X[i];
            int curY = y + Y[i];
            if(curX<0 || curX>=n)continue;
            if(curY<0 || curY>=m)continue;
            
            if(board[curX][curY]<2){
                sum+= board[curX][curY];
            } else if (board[curX][curY]>=4){
                sum++;
            }
        }
        
        return sum;
    }
}
