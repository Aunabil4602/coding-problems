//unordered_map<int,int> par,sz;  if index has no limit
int par[N],sz[N];

int parent(int x)
{
    int cur=x;
    while(cur!=par[cur]){
        cur=par[par[cur]];
    }
    return par[x]=cur;
}

void join(int x,int y)
{
    int pX=parent(x),pY=parent(y);
    if(sz[pX]>sz[pY]){
        par[pY]=pX;
        sz[pX]+=sz[pY];
    }
    else {
        par[pX]=pY;
        sz[pY]+=sz[pX];
    }
}
