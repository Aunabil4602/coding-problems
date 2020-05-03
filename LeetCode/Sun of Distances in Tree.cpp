// complexity O(n)
// in dfs1 we calculated number of nodes and total distances(dis[NN]) in subtree(childs[NN]) for each node v.
// in dfs2 we calculated the the total distances from all nodes by merging parent's and current node's data.

#define NN 10005

vector<int> adj[NN];
int childs[NN];
int dis[NN];
int n;

void dfs1(int v,int p)
{
    childs[v]=1;
    for(auto x:adj[v]){
        if(x==p)continue;
        dfs1(x,v);
        childs[v]+=childs[x];
        dis[v]+=dis[x]+childs[x];
    }
}

void dfs2(int v,int p)
{
    if(p!=-1)dis[v]=(dis[p]-(dis[v]+childs[v])+(n-childs[v]))+dis[v];
    for(auto x:adj[v]){
        if(x==p)continue;
        dfs2(x,v);
    }
}

class Solution {
public:
    
    vector<int> sumOfDistancesInTree(int N, vector<vector<int>>& edges) {
        for(int i=0;i<N;i++){
            adj[i].clear();
            dis[i]=0;
            childs[i]=0;
        }
        n=N;
        
        for(auto x:edges){
            adj[x[0]].push_back(x[1]);
            adj[x[1]].push_back(x[0]);
        }
        
        dfs1(0,-1);
        dfs2(0,-1);
        vector<int> ans;
        for(int i=0;i<N;i++)ans.push_back(dis[i]);
        return ans;
    }
};
