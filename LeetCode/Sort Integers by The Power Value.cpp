class Solution {
public:
    unordered_map<int,int> dp;
    
    int getKth(int lo, int hi, int k) {
        dp.clear();
        
        vector<pair<int,int> > arr;
        
        for(int i=lo;i<=hi;i++){
            arr.push_back({fDP(i),i});
        }
        
        sort(arr.begin(),arr.end());
        return arr[k-1].second;
    }
    
    int fDP(int v) {
        if(v==1)return 1;
        if(dp[v]!=0)return dp[v]; 
        
        dp[v] = 1+ fDP((v&1)?(3*v+1):(v/2));
        
        return dp[v];
    }
};
