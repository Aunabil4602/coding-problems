// bfs, O(n*m)

#include<bits/stdc++.h>
#define N 1005
using namespace std;

int change[N][N];
int dp[N][N];
string s[N];
int cX[]={0,0,-1,1};
int cY[]={-1,1,0,0};

int main()
{
    int n,m,t;
    cin>>n>>m>>t;
    for(int i=0;i<n;i++)cin>>s[i];

    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            dp[i][j]=INT_MAX;
            change[i][j]=0;
            for(int k=0;k<4;k++){
                int nX=i+cX[k];
                int nY=j+cY[k];
                if(nX<0 || nX==n)continue;
                if(nY<0 || nY==m)continue;
                if(s[nX][nY]==s[i][j])change[i][j]=1,dp[i][j]=0;
            }
        }
    }

    queue<pair<int,int> > q;
    for(int i=0;i<n;i++)for(int j=0;j<m;j++){
        if(change[i][j])q.push({i,j});
    }

    while(!q.empty()){
        auto cur=q.front();
        q.pop();
        int x=cur.first,y=cur.second;
        change[x][y]=1;
        for(int i=0;i<4;i++){
            int nX=x+cX[i];
            int nY=y+cY[i];
            if(nX<0 ||nX==n)continue;
            if(nY<0 ||nY==m)continue;
            if(!change[nX][nY] && dp[x][y]+1<dp[nX][nY]){
                if(dp[nX][nY]==INT_MAX)q.push({nX,nY});
                dp[nX][nY]=1+dp[x][y];
            }
        }
    }

    long long x,y,p;

    while(t--){
        cin>>x>>y>>p;
        x--;
        y--;
        long long rem=max<long long>(0,p-(long long)dp[x][y]);
        if(dp[x][y]==INT_MAX)rem=0;
        if(rem&1)cout<<(!(s[x][y]-'0'))<<endl;
        else cout<<(s[x][y]-'0')<<endl;

    }
}
