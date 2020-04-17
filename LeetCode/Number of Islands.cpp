class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        int n=grid.size();
        if(n==0)return 0;
        int m=grid[0].size();
        
        int dp[n][m];
        memset(dp,0,sizeof(dp));
        int X[]={0,0,1,-1};
        int Y[]={1,-1,0,0};
        int ans=0;
        for(int i=0;i<n;i++)for(int j=0;j<m;j++){
            if(grid[i][j]=='1' && !dp[i][j]){
                ans++;
                queue<pair<int,int> >q;
                q.push({i,j});
                dp[i][j]=1;
                while(!q.empty()){
                    pair<int,int> cur=q.front();
                    q.pop();
                    for(int k=0;k<4;k++){
                        int x=cur.first+X[k];
                        int y=cur.second+Y[k];
                        if(x<0 || x>=n)continue;
                        if(y<0 || y>=m)continue;
                        if(grid[x][y]=='1' && !dp[x][y]){
                            dp[x][y]=1;
                            q.push({x,y});
                        }
                    }
                }
            }
        }
        return ans;
    }
};
