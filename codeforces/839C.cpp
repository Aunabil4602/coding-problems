#include<bits/stdc++.h>
#define N 1000005

using namespace std;

vector<int> adj[N];
int dis[N];
int n,x,y;
double ans=0;

void dfs(int v,int p,double prob)
{
    if(p!=-1)dis[v]=dis[p]+1;
    else dis[v]=0;

    if(adj[v].size()==1 && v!=1){
        ans+=prob*dis[v];
        return;
    }

    prob/=(adj[v].size()-1*(p!=-1));
    for(auto x: adj[v]){
        if(x==p)continue;
        dfs(x,v,prob);
    }
}

int main()
{
    cin>>n;
    for(int i=1;i<n;i++){
        cin>>x>>y;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }

    dfs(1,-1,1);
    cout<<fixed;
    cout<<setprecision(8);
    cout<<ans<<endl;
}
