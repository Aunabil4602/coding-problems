class Solution {
public:
    int dp1[100005], dp2[100005];
    int n=100005;
  
    int numTeams(vector<int>& rating) {
        memset(dp1,0,sizeof dp1);
        memset(dp2,0,sizeof dp2);
        
        for(auto &x: rating) {
            update2(x,1);
        }
        
        int ans=0;
        update1(rating[0],1);
        update2(rating[0],-1);
        
        for(int i=1;i<rating.size()-1;i++){
            int leftS = query1(rating[i]-1);
            int rightL = query2(100000) - query2(rating[i]);
            int rightS = query2(rating[i]-1);
            int leftL = query1(100000) - query1(rating[i]);
            
            ans += leftS*rightL + leftL*rightS;
            
            update1(rating[i],1);
            update2(rating[i],-1);
        }
        
        return ans;
    }
    
    void update1(int x, int val) {
        while(x<n) {
            dp1[x]+=val;
            x+=(-x&x);
        }
    }
    
    int query1(int x) {
        int sum = 0;
        while(x>0) {
            sum+=dp1[x];
            x-=(-x&x);
        }
        return sum;
    }
    
    void update2(int x, int val) {
        while(x<n) {
            dp2[x]+=val;
            x+=(-x&x);
        }
    }
    
    int query2(int x) {
        int sum = 0;
        while(x>0) {
            sum+=dp2[x];
            x-=(-x&x);
        }
        return sum;
    }
};
