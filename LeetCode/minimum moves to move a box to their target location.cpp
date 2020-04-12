#define N 25
#define MM 1000
int dp[N][N];
int n,m;

int check(int vv,int hh,pair<int,int> hum, pair<int,int> box,vector<vector<char>>& grid)
{
    if(vv<0 || vv>=n)return 0;
    if(hh<0 || hh>=m)return 0;
    char temp=grid[box.first][box.second];
    grid[box.first][box.second]='#';

    int dp1[N][N];
    for(int i=0;i<N;i++){
        for(int j=0;j<N;j++){
            dp1[i][j]=1000;
        }
    }
    queue<pair<int,int> > q;
    q.push(hum);
    dp1[hum.first][hum.second]=0;

    while(!q.empty()){
        pair<int,int> cur=q.front();
        q.pop();
        int v=cur.first;
        int h=cur.second;

        if(h>0 && dp1[v][h-1]==MM && grid[v][h-1]!='#'){
            dp1[v][h-1]=1+dp1[v][h];
            q.push(make_pair(v,h-1));
        }
        if(v>0 && dp1[v-1][h]==MM && grid[v-1][h]!='#'){
                dp1[v-1][h]=1+dp1[v][h];
                q.push(make_pair(v-1,h));
        }
        if(h<(m-1) && dp1[v][h+1]==MM && grid[v][h+1]!='#'){
            dp1[v][h+1]=1+dp1[v][h];
            q.push(make_pair(v,h+1));
        }
        if(v<(n-1) && dp1[v+1][h]==MM && grid[v+1][h]!='#'){
            dp1[v+1][h]=1+dp1[v][h];
            q.push(make_pair(v+1,h));
        }
    }
    grid[box.first][box.second]=temp;
    if(dp1[vv][hh]!=MM)return 1;
    return 0;

}

class Solution {
public:
    int minPushBox(vector<vector<char>>& grid) {
        for(int i=0;i<N;i++){
            for(int j=0;j<N;j++){
                dp[i][j]=1000;
            }
        }

        pair<int,int> posB,posT,posS;
        n=grid.size();
        m=grid[0].size();
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]=='S')posS=(make_pair(i,j));
                if(grid[i][j]=='T')posT=(make_pair(i,j));
                if(grid[i][j]=='B')posB=(make_pair(i,j));
            }
        }



        queue<pair<int,int> >q;
        queue<pair<int,int> >pre;
        queue<pair<int,int> >human;

        q.push(posB);
        human.push(posS);
        dp[posB.first][posB.second]=0;

        while(!q.empty()){
            pair<int,int> cur=q.front();
            pair<int,int> hum=human.front();
            q.pop();
            human.pop();

            int v=cur.first,h=cur.second;
            if(h>0 && dp[v][h-1]==MM && grid[v][h-1]!='#' && check(v,h+1,hum,cur,grid)){
                dp[v][h-1]=1+dp[v][h];
                q.push(make_pair(v,h-1));
                human.push(make_pair(v,h));
            }
            if(v>0 && dp[v-1][h]==MM && grid[v-1][h]!='#' && check(v+1,h,hum,cur,grid)){
                dp[v-1][h]=1+dp[v][h];
                q.push(make_pair(v-1,h));
                human.push(make_pair(v,h));
            }
            if(h<(m-1) && dp[v][h+1]==MM && grid[v][h+1]!='#' && check(v,h-1,hum,cur,grid)){
                dp[v][h+1]=1+dp[v][h];
                q.push(make_pair(v,h+1));
                human.push(make_pair(v,h));
            }
            if(v<(n-1) && dp[v+1][h]==MM && grid[v+1][h]!='#' && check(v-1,h,hum,cur,grid)){
                dp[v+1][h]=1+dp[v][h];
                q.push(make_pair(v+1,h));
                human.push(make_pair(v,h));
            }
        }

        int ans=dp[posT.first][posT.second];
        if(ans==MM)return -1;
        return ans;
    }
};

