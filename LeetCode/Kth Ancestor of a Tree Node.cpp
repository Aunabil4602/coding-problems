class TreeAncestor {
    vector<int> parent;
    int n;
    int dp[50005][16];
public:
    TreeAncestor(int n, vector<int>& parent) {
        this->parent=parent;
        this->n=n;
        
        for(int i=0;i<n;i++){
            dp[i][0] = parent[i];
        }
        for(int i=1;i<16;i++){
            for(int j=0;j<n;j++){
                if(dp[j][i-1]==-1)dp[j][i]=-1;
                else dp[j][i] = dp[ dp[j][i-1] ][i-1];
            }
        }
    }
    
    int getKthAncestor(int node, int k) {
        for(int i=0;i<16;i++){
            if((k>>i)&1){
                node = dp[node][i];  
                if(node==-1)return node;
            }
        }
        return node;
    }
};

/**
 * Your TreeAncestor object will be instantiated and called as such:
 * TreeAncestor* obj = new TreeAncestor(n, parent);
 * int param_1 = obj->getKthAncestor(node,k);
 */
