class Solution {
public:
    int numSquares(int n) {
        int N=n+10;
        vector<int> squares;
        for(int i=1;i*i<N;i++){
            squares.push_back(i*i);
        }
        
        int dp[N];
        for(int i=0;i<N;i++)dp[i]=1e7;
        dp[0]=0;
        for(auto x:squares){
            for(int i=0;i+x<N;i++){
                dp[i+x]=min(dp[i+x],dp[i]+1);
            }
        }
        
       return dp[n];
    }
};
